cpp-ngram-builder
=================

Small Class to build ngrams

Requirements
------------

* boost/tokenizer.hpp

Usage
-----

    auto got_2_grams = aux::NGramBuilder<>::build_ngrams(line, 2);
    
See the provided test cases for further information.

License
-------

[WTFPL](http://www.wtfpl.net/)