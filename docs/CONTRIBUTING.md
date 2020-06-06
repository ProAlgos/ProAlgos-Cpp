# Contribution Guidelines

## Contents

* [Getting started](#getting-started)
* [Writing code](#writing-code)
* [Testing code](#testing-code)
* [Opening a pull request](#opening-a-pull-request)
* [Code of conduct](#code-of-conduct)

## Getting started

* Start by exploring the repository. Take a look at how the algorithms and data structures are implemented, how tests are written, and which files go where.

* Before beginning your contribution, [create an issue][issue-guide]. In your issue's description, please describe the addition or change you wish to make. This helps others guide your contribution, and it lets others know what you're working on.

* [Fork][fork-guide] the repo, then clone your fork and configure the remotes:

   ```bash
   # Clone your fork of the repo into the current directory
   git clone https://github.com/<your-username>/ProAlgos-Cpp.git

   # Navigate to the newly cloned directory
   cd ProAlgos-Cpp

   # Assign the original repo to a remote called "upstream"
   git remote add upstream https://github.com/ProAlgos/ProAlgos-Cpp.git
   ```

* If you cloned a while ago, get the latest changes from upstream:

   ```bash
   git checkout master
   git pull upstream master
   ```

* Create a new branch (starting from the `master` branch) to contain your code for a specific algorithm or data structure:

   ```bash
   git checkout -b <branch-name>
   ```

## Writing code

* Start by reviewing our [C++ coding guidelines][coding-guidelines].

* Commit your changes in logical chunks. Use Git's [interactive rebase][rebase-info]
  feature to tidy up your commits before making them public. For more info, see the following [interactive rebase guide][rebase-guide].

* For each algorithm, mention its **time complexity** and **space complexity**
  in the _"description comment"_ of its implementation. In case the average-case
  and worst-case complexities are different, mention both of them.

    The format for the _"description comment"_ (which is written at the beginning) should be:

    ```text
    <Name of algorithm>
    -------------------
    <Brief description>

    Time complexity
    ---------------
    O(...), where <description of variable(s)>

    Space complexity
    ----------------
    O(...), where <description of variable(s)>
    ```

* Before you push your changes to GitHub, make sure that your code compiles and runs without any errors or warnings.

## Testing code

Algorithms and data structures are implemented as header files (.hpp) in the [`include` directory][include-dir] and then verified via unit test files (.cpp) in the [`test` directory][test-dir]. If you're adding an algorithm or data structure, you'll write both the implementation and the unit tests.

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
   at the [existing unit tests][test-dir] to get a clearer idea about how the
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

## Opening a pull request

Follow these steps when you're ready to submit your code:

1. Locally merge (or rebase) the upstream development branch into your branch:

   ```bash
   git pull [--rebase] upstream master
   ```

1. Push your branch up to your fork:

   ```bash
   git push origin <branch-name>
   ```

1. [Open a pull request][pr-guide] with a clear title and description against the
   `master` branch. Your pull request should reference the same issue you created
   above.

1. Once your pull request has been opened, we'll review it and go from there. :smile:

## Code of Conduct

This project has a [Code of Conduct](CODE_OF_CONDUCT.md). Please follow it in all your interactions with the project.

[coding-guidelines]: CODING_GUIDELINES.md
[fork-guide]: https://help.github.com/fork-a-repo/
[rebase-info]: https://help.github.com/en/github/using-git/about-git-rebase
[rebase-guide]: https://hackernoon.com/beginners-guide-to-interactive-rebasing-346a3f9c3a6d
[pr-guide]: https://help.github.com/articles/about-pull-requests/
[issue-guide]: https://help.github.com/en/articles/about-issues
[catch]: https://github.com/catchorg/Catch2
[catch-tutorial]: https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#writing-tests
[include-dir]: https://github.com/ProAlgos/ProAlgos-Cpp/tree/master/cpp/include
[test-dir]: https://github.com/ProAlgos/ProAlgos-Cpp/tree/master/cpp/test
