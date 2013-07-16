#define BOOST_TEST_MODULE NGramBuilderTest

#ifdef HEADER_ONLY
#   include <boost/test/included/unit_test.hpp>
#else
#   include <boost/test/unit_test.hpp>
#endif

#include <string>
#include <list>
#include "NGramBuilder.hpp"

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE( test_suite1 )

struct Fixture {
    std::string         line = {"The quick brown fox jumps over the lazy dog ."};

    std::list<std::string>  expected_2 = {
        /* 1-grams */
        "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", ".",
        /* 2-grams */
        "The quick", "quick brown", "brown fox", "fox jumps", "jumps over",
        "over the", "the lazy", "lazy dog", "dog ."
    };

    std::list<std::string>  expected_3 = {
        /* 1-grams */
        "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", ".",
        /* 2-grams */
        "The quick", "quick brown", "brown fox", "fox jumps", "jumps over",
        "over the", "the lazy", "lazy dog", "dog .",
        /* 3-grams */
        "The quick brown", "quick brown fox", "brown fox jumps",
        "fox jumps over", "jumps over the", "over the lazy",
        "the lazy dog", "lazy dog ."
    };
};

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE( test_case_1 )
{
    Fixture f;
    auto got_2 = aux::NGramBuilder<>::build_ngrams(f.line, 2);

    // BOOST_TEST_MESSAGE("Testing correct value(s)...");

    BOOST_REQUIRE_EQUAL_COLLECTIONS(
        std::begin(got_2),      std::end(got_2),
        std::begin(f.expected_2), std::end(f.expected_2)
    );
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE(test_case_2)
{
    Fixture f;
    
    auto got_3 = aux::NGramBuilder<std::list<std::string>>::build_ngrams(f.line, 3);
    
    BOOST_TEST_MESSAGE("Testing correct value(s)...");

    BOOST_REQUIRE_EQUAL_COLLECTIONS(
        std::begin(got_3),      std::end(got_3),
        std::begin(f.expected_3), std::end(f.expected_3)
    );
}
//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()
