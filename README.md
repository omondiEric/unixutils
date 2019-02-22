# Unix Utilities, System Calls, and C
Your task for this lab is to implement "lite" versions of 4 important Unix utilities (`cat`, `grep`, `zip`, and `unzip`), each in their own `.c` file. Please pay careful attention to the **Details** sections on the [Lab webpage](http://cs.williams.edu/~jannen/teaching/s19/cs333/labs/unix-utils/index.html) as you complete and verify your implementations.

## Useful Links
 * [Lab Page](http://cs.williams.edu/~jannen/teaching/s19/cs333/labs/unix-utils/index.html)
 * [Linux Manual Pages](https://linux.die.net/man/)
 * [OSTEP Chapter 39](http://pages.cs.wisc.edu/~remzi/OSTEP/file-intro.pdf)

## Sample Code
 * The `sample/` directory contains two useful files to help you get reacquainted with C.
   * `sample/Makefile` : an example Makefile that you can use/extend as a pattern for your own. Improvements are appreciated, and if you create a particularly well-written Makefile, I will share it with the class so everyone can benefit.
   * `sample/my-stat.c` : a simple C program that calls the `stat` C library function (which in turn calls the `stat` system call). You may wish to use several elements from this example in your Unix utility implementations---it imports appropriate C header files, uses `perror` and `errno` to identify/report errors, makes a simple system call, and prints some results to standard output.
 * `.gitignore` : please commit all of your source files, but avoid commiting automatically generated and backup files. Feel free to modify this as you see fit.

# Repository Details
  * my-cat.c: Mimics the UNIX cat command, with the exception of reading from stdin when no file is specified.  We used Kernighan and Ritchie's C book to help us get used to C again, and of course the man pages.  If an invalid file is specified, and error message will print and execution will stop on that file (but after executing previous files).  To run, assuming the compiled file is named my-cat: ./my-cat file1 [file2 ...].
  * my-grep.c: Mimics the UNIX grep command.  We again turned to Kernighan and Ritchie for some advice.  If an invalid file is specified, an error message will print and execution will stop on that file (but after executing previous files).  To run, assuming the compiled file is named my-grep: ./my-grep searchterm [file ...].
  * my-zip.c: Zips a file by saving each character (or one copy, if repeated) preceded by a four-bit integer in binary format representing the number of times that character has repeated.  We talked to Bill a lot about specifics and to smooth out some problems with getwrite.  We talked with Chris and Noah about one test case, which turned out to not work as a test (found that out after talking to Bill).  If an invalid file is specified, an error message will print and execution will stop on that file (but after executing previous files).  To run, assuming the compiled file is named my-zip: ./my-zip file1 [file2 ...].
  * my-unzip.c: Unzips a binary file zipped by my-zip.c and prints out the original file.  If an invalid file is specified, an error message will print and execution will stop on that file (but after executing previous files).  To run, assuming the compiled file is named my-unzip: ./my-unzip file1 [file2...].


We are the sole authors of the work in this repository.