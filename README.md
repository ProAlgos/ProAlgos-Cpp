# Algos
Implementation of well-known (and some rare) algorithms, mostly in C++.

## Contents
Check out the [Wiki](https://github.com/faheel/Algos/wiki/Contents) for a complete list of contents.

## My goal
> Add atleast 1 algorithm to the repo every week.

### Want to contribute to open-source and help me achieve the goal?
1. **Fork** the repo :fork_and_knife: (and don't forget to star!)
2. **Add your implementation** of an algorithm that is not already in the repo (preferably in C++, but others would do just fine)
3. Submit a **pull request** ([click here to learn how](https://help.github.com/articles/creating-a-pull-request-from-a-fork/ "Learn how to create a pull request"))

#### Want to suggest some algorithms to add?
Just [create a new issue](https://github.com/faheel/algos/issues/new "Create a new issue") and I'll handle it from there :smile:

## C++ coding guidelines
If you are contributing C++ code to this repo, make sure to read the [C++ coding guidelines](C++CodingGuidelines.md).

## Compiling C++ code
Since many of the C++ programs in this repo use new features of C++11 (like range-based for-loops and more), you will need to use the `-std=c++11` flag if you are compiling using the CLI. If you use an IDE, make sure to set the standard as **C++11** in your compiler settings.

Also make sure there are no warnings during compilation by setting the `-Wall` flag and checking that nothing gets reported, if using the CLI. If using an IDE, make sure to check the "**Enable all warnings**" option for your compiler.

#### An example
If you are in the _Sorting_ directory, and want to compile the code for _merge sort_, run the following command:
```
g++ -std=c++11 -Wall -o MergeSort.out MergeSort.cpp
```
Instead of _g++_, you may use other compilers like _gcc_, _clang_, _clang++_, _MinGW_ (Windows) or _Visual C++_ (Windows). Just make sure that they support C++11 features.
