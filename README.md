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
 **Pleaes fill this section in with any details necessary to understand, compile, and run your code.**