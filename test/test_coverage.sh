#!/bin/sh

for file in cfarmhash
do
    echo [$file]
    test=`gcov -b src/libcfarmhash_test_a-$file | grep -A4 File.*$file`
    echo "$test"
    echo "$test" | grep '% of' | grep '100.00%' >/dev/null || exit 1
    echo "$test" | grep '% of' | grep -v '100.00%' >/dev/null && exit 1
done
exit 0

