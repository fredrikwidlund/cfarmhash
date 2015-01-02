libcfarmhash
============

C port of the Farmhash Hash64 (farmhashna) hash function

Installation
------------

    ./autogen.sh
    ./configure
    make
    sudo make install

Tests
-----

Requires cmocka (http://cmocka.org/) to be installed.

    make check


The tests require 100% code coverage to succeed.

    $ cat test/test_coverage.sh.log
    [cfarmhash]
    File 'src/cfarmhash.c'
    Lines executed:100.00% of 109
    Branches executed:100.00% of 14
    Taken at least once:100.00% of 14
    Calls executed:100.00% of 67

Example
-------

    $ cat example.c
    #include <stdio.h>
    #include <stdint.h>
    #include <string.h>
    #include <cfarmhash.h>
    
    int main(int argc, char **argv)
    {
    int i;
    for (i = 1; i < argc; i ++)
      (void) printf("%08lx\n", cfarmhash(argv[i], strlen(argv[i])));
    }
    $ cc -Wall -Wextra -Wpedantic -O3 -flto -std=c11 example.c   -o example -lcfarmhash
    $ ./example stringtohash
    e31cec1feff14d6b
