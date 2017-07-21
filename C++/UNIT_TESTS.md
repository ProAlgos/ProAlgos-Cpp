## Adding unit tests for C++ code

1. Under the [`test` directory](test), locate (or create, if doesn't exist) the directory having the same relative path from `test` as from `source` or `include`.
**Eg.** if you added the source code to `source/dir1/`, locate or create the directory `test/dir1`.

1. Create a file with the same name as the corresponding source file for which you are writing tests, except that the extension should be `.test.cpp` instead of just `.cpp`.

1. Add the following code to the test file:
    ```C++
    #define NAME_OF_FILE_TEST
    #define CATCH_CONFIG_MAIN

    #include "third_party/catch.hpp"
    #include "source/path_to/source_file.cpp"

    // Add your test cases here:



    // don't write anything after this line!
    #undef NAME_OF_FILE_TEST
    ```

1. Add your tests between the two comments, and then remove the comments afterwards.

1. In `NAME_OF_FILE_TEST`, replace `NAME_OF_FILE` with the name of the file for which you are writing the tests, but all in uppercase, with words separated by an underscore (`_`).
**Eg.** for `hello_world_again.cpp`, `NAME_OF_FILE` should be replaced with `HELLO_WORLD_AGAIN`.

1. Wrap the `main()` function of your source code within the following:
    ```C++
    #ifndef NAME_OF_FILE_TEST
    int main() {
        // ...
    }
    #endif
    ```

**And that's it!** Now you can compile the test using **`make test`** from the `C++` directory, which will also run all of the tests for you. In order to run only a specific test and see its results, run it manually from the `bin` directory.
