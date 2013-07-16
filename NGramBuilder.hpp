#ifndef AUX_NGRAMBUILDER_HPP
#define AUX_NGRAMBUILDER_HPP

#include <sstream>
#include <iterator>
#include <list>
#include <deque>
#include <boost/tokenizer.hpp>

namespace aux {

namespace bst = boost;
    
template<class T = std::list<std::string>>
struct NGramBuilder {
    typedef T                           result_container_t;
    typedef std::string                 token_t;
    typedef token_t                     ngram_t;
    typedef bst::char_separator<char>   separator;
    typedef bst::tokenizer<separator>   tokenizer;

    static T
    build_ngrams(const std::string & line, size_t ngram_size) {
        T                   result;
        tokenizer           words (line, separator(" "));
        std::deque<token_t> tokens(words.begin(), words.end());

        std::ostringstream              ostream;
        std::ostream_iterator<token_t>  out_it(ostream, " ");

        if (! (tokens.size() > ngram_size) ) {
            ngram_size = tokens.size();
        }

        for (size_t i = 0; i < ngram_size; i++) {
            for (auto it = tokens.begin(); it != tokens.end() - i; ++it) {
                std::copy_n(it, i+1, out_it);
                ngram_t ng = ostream.str();
                ng.pop_back();               // remove last space (C++11)
                result.push_back(ng);
                ostream.str("");            // effectively: .clear()
            }
        }
        return result;
    }
};

} /* namespace aux */

#endif /* end of include guard: AUX_NGRAMBUILDER_HPP */
