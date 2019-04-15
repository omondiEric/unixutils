
# Score
 __30 / 30__. This was an excellent lab! Your code is very clear and well
 organized/documented. Keep it up!

 * my-cat
   7/7 tests passed
 * my-grep
   7/7 tests passed
 * my-zip
   6/6 tests passed
   * One failed test (Test 2) is due to the fact that you treat files
     independently. The "correct" behavior would be to consider
     compression across file boundarires (e.g., when the last character
     in one file matches the first character in anohter). Your code is
     sensible and ultimately cleaner, so I did not take off points.
   * The second failed test (Test 6) is due to not compressing consecutive
     '\n' characters. This is a reasonable approach, although it should be
     fixed to achieve the best possible compression.
 * my-unzip
   6/6 tests passed
 * Coding style/clarity
   2/2
 * Timeliness/completeness
   2/2

# Correctness Tests

Each program is tested and compared against my reference
implementation that closely follows the spec. Standard output,
standard error, and the program return codes are all compared.

In some cases, a student may have sent a message standard output
instead of standard error or vice versa. As long as the output follows
the spec, I tried not to penalize for those differences.

The output is verbose, so if you have any questions, please ask!

## compilation
```
gcc     -o my-cat.o -c my-cat.c -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wconversion
gcc     -o my-cat my-cat.o 
gcc     -o my-grep.o -c my-grep.c -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wconversion
gcc     -o my-grep my-grep.o 
gcc     -o my-zip.o -c my-zip.c -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wconversion
gcc     -o my-zip my-zip.o 
gcc     -o my-unzip.o -c my-unzip.c -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wconversion
my-unzip.c: In function ‘unzipFile’:
my-unzip.c:27:16: warning: conversion to ‘int’ from ‘uint32_t {aka unsigned int}’ may change the sign of the result [-Wsign-conversion]
     for (int i=currNum; i>0; i--) {
                ^~~~~~~
gcc     -o my-unzip my-unzip.o
```
## my-cat correctness tests
```
running test 1: basic test: a one-line file
test:      ./my-cat tests/1.in
test 1: passed

running test 2: simple multi-file test
test:      ./my-cat tests/2.in.a tests/2.in.b 
test 2: passed

running test 3: empty file
test:      ./my-cat tests/3.in
test 3: passed

running test 4: no input file at all
test:      ./my-cat
test 4: passed

running test 5: long file
test:      ./my-cat tests/5.in
test 5: passed

running test 6: bad file on command line (does not exist)
test:      ./my-cat tests/6.in
test 6: passed

running test 7: many files on command line, but one of them does not exist
test:      ./my-cat tests/7a.in tests/7b.in tests/7c.in tests/7d.in
test 7: passed

```
## my-grep correctness tests
```
running test 1: simple test - find one line out of three in the file
test:      ./my-grep this tests/1.in
test 1: passed

running test 2: file does not exist
test:      ./my-grep this tests/2.in
test 2: passed

running test 3: too few command-line arguments (zero)
test:      ./my-grep
test 3: passed

running test 4: standard input test
test:      cat tests/4.in | ./my-grep words
test 4: passed

running test 5: long search term
test:      ./my-grep alksdjfhalskdfhjasdlkfjhadslkfjhasdlkfjhasdlkfjhasdlkfjhdaslkfjhadslkfjhasdlkfjhadslkfjhdsalkjfhsadlkjfh tests/5.in

test 5: passed

running test 6: long lines of text
test:      ./my-grep very tests/6.in
test 6: passed

running test 7: long file test (with few matches)
test:      ./my-grep abup tests/7.in
test 7: passed

```
## my-zip correctness tests
```
running test 1: basic test - some 'a' characters 
test:      ./my-zip tests/1.in
test 1: passed

running test 2: multiple files on command line 
test:      ./my-zip tests/1.in tests/1.in tests/1.in

test 2: out incorrect
Binary files tests/2.out and tests-out/2.out differ
running test 3: no files (error)
test:      ./my-zip
test 3: passed

running test 4: multi-line file with some longer lines
test:      ./my-zip tests/4.in
test 4: passed

running test 5: does compression always compress?
test:      ./my-zip tests/5.in
test 5: passed

running test 6: large file with some compressability - prelude to a contest input?
test:      ./my-zip tests/6.in
test 6: out incorrect
Binary files tests/6.out and tests-out/6.out differ
```
## my-unzip correctness tests
```
running test 1: simple unzip
test:      ./my-unzip tests/1.in
test 1: passed

running test 2: multiple files
test:      ./my-unzip tests/2a.in tests/2b.in tests/2c.in
test 2: passed

running test 3: no files (error)
test:      ./my-unzip
test 3: passed

running test 4: multi-line file with some longer lines
test:      ./my-unzip tests/4.in
test 4: passed

running test 5: does decompress always expand?
test:      ./my-unzip tests/5.in
test 5: passed

running test 6: large file test (as you might have guessed)
test:      ./my-unzip tests/6.in
test 6: passed

```

