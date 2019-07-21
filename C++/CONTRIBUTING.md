# C++ Contribution Guidelines

This page describes the specifics of implementing algorithms and data structures in C++. If you have not already done
so, please read the [general contribution guidelines][contrib-guide].

## Contents

* [Coding guidelines](#coding-guidelines)
* [Unit tests](#unit-tests)

## Coding guidelines

This project adheres to the [C++ Coding Guidelines](../C++/CODING_GUIDELINES.md). Please read (and follow!) them.

## Unit tests

Algorithms and data structures are implemented as header files (.hpp) in the [`include` directory](include) and then verified via
unit test files (.cpp) in the [`test` directory](test). If you're adding an algorithm or data structure, you'll write both
the implementation and the unit tests. 

#### Adding unit tests

1. Under `test`, locate (or create, if it doesn't exist)
   the directory having the same relative path from `test` as from `include`.
   For example, if you've created a header file in `include/algorithm/searching`,
   locate (or create) the directory `test/algorithm/searching`.

1. Create a file with the same name as the corresponding header file for which
   you are writing tests, except that the extension should be `.cpp`.

1. Add the following code to the test file:

    ```cpp
    #include "third_party/catch.hpp"
    #include "path/to/header_file.hpp"
    ```

    The path to the header file is relative from the `include` directory. So,
    for instance, if you need to include the header file
    `include/algorithm/searching/linear_search.hpp`, you can write:

    ```cpp
    #include "algorithm/searching/linear_search.hpp"
    ```

1. After these lines you can add your test cases. For details regarding how to
   write test cases using the [Catch test framework][catch], I suggest you to
   go through [this short tutorial][catch-tutorial]. You can also take a look
   at the [existing unit tests][unit-tests] to get a clearer idea about how the
   tests are written.

1. Add an entry for your unit test in `CMakeLists.txt`. For example, if your
   unit test is `test/algorithm/searching/linear_search.cpp`, add the following
   entry for it:

   ```cmake
    add_executable(linear_search
           test/algorithm/searching/linear_search.cpp)
    target_link_libraries(linear_search test_runner)
   ```

That's it! Now you can compile the test using **`make test`** from the
`C++` directory, which will also run all of the tests for you. In order to run
only a specific test and see its results, run it manually from the `bin` directory.

[contrib-guide]: .github/CONTRIBUTING.md
[catch]: https://github.com/catchorg/Catch2
[catch-tutorial]: https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#writing-tests
[unit-tests]: https://github.com/faheel/Algos/tree/master/C%2B%2B/test