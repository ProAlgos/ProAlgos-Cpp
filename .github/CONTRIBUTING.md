# Contribution Guidelines

## Contents

* [Getting started](#getting-started)
* [Writing code](#writing-code)
* [Adding unit tests](#adding-unit-tests)
* [Opening a pull request](#opening-a-pull-request)
* [Code of conduct](#code-of-conduct)

## Getting started

* Start by exploring the repository. Take a look at how the algorithms are implemented, how tests
  are written, and which files go where. 

* Read the [C++ contribution guidelines](../C++/CONTRIBUTING.md).

* Before beginning your contribution, [create an issue][issue-guide]. In your issue's 
  description, please describe the addition or change you wish to make. This helps us guide 
  your contribution, and it lets others know what you're working on.

* [Fork][fork-guide] the repo, clone your fork, and configure the remotes:

   ```bash
   # Clone your fork of the repo into the current directory
   git clone https://github.com/<your-username>/Algos.git
   # Navigate to the newly cloned directory
   cd Algos
   # Assign the original repo to a remote called "upstream"
   git remote add upstream https://github.com/faheel/Algos.git
   ```

* If you cloned a while ago, get the latest changes from upstream:

   ```bash
   git checkout master
   git pull upstream master
   ```

* Create a new branch (from the `master` branch) to contain your code for a
   specific algorithm or data structure:

   ```bash
   git checkout -b <branch-name>
   ```

## Writing code

* Commit your changes in logical chunks. Use Git's [interactive rebase][rebase-guide]
  feature to tidy up your commits before making them public.

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

## Adding unit tests

* As stated above, all algorithms and data structures are verified via unit tests.
  
* Please make sure that your contribution includes a variety of unit tests and that all of your unit tests pass.

* You can find more information about writing unit tests [here](../C++/CONTRIBUTING.md). 

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

[fork-guide]: https://help.github.com/fork-a-repo/
[rebase-guide]: https://help.github.com/articles/interactive-rebase
[pr-guide]: https://help.github.com/articles/about-pull-requests/
[issue-guide]: https://help.github.com/en/articles/about-issues