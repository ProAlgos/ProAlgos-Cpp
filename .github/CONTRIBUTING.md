# Contributing Guidelines

### Contents

* [General guidelines](#general-guidelines)
* [C++ coding guidelines](#c-coding-guidelines)
* [Pull requests](#pull-requests)
* [Code of conduct](#code-of-conduct)

## General guidelines

* When contributing to this repository, please first inform or discuss the
  change(s) you wish to make via an issue. This helps in letting others know
  what you're working on.

* For each algorithm, mention its **time complexity** and **space complexity**
  in the _"description comment"_ of its implementation. In case the average-case
  and worst-case complexities are different, mention both of them.

    The format for the _"description comment"_ (which is written at the beginning) should be:
    ```
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

## C++ coding guidelines

If you are contributing C++ code to this repo, make sure to read the [C++ Coding Guidelines](../C++/CODING_GUIDELINES.md).

## Pull requests

Follow the steps below to contribute to the project:

1. [Fork][fork-guide] the repo, clone your fork, and configure the remotes:

   ```bash
   # Clone your fork of the repo into the current directory
   git clone https://github.com/<your-username>/Algos.git
   # Navigate to the newly cloned directory
   cd Algos
   # Assign the original repo to a remote called "upstream"
   git remote add upstream https://github.com/faheel/Algos.git
   ```

2. If you cloned a while ago, get the latest changes from upstream:

   ```bash
   git checkout reorganise
   git pull upstream reorganise
   ```

<<<<<<< HEAD:CONTRIBUTING.md
3. Create a new branch (off the `reorganise` branch) to contain your code for a specific algorithm or data structure:
=======
3. Create a new branch (off the `reorganise` branch) to contain your code for a
   specific algorithm or data structure:
>>>>>>> 3b3187f7c1be4be7cbb5c20ccf1d0486770e3379:.github/CONTRIBUTING.md

   ```bash
   git checkout -b <branch-name>
   ```

4. Commit your changes in logical chunks. Use Git's [interactive rebase][rebase-guide]
   feature to tidy up your commits before making them public.

5. Locally merge (or rebase) the upstream development branch into your branch:

   ```bash
   git pull [--rebase] upstream reorganise
   ```

6. Push your branch up to your fork:

   ```bash
   git push origin <branch-name>
   ```

<<<<<<< HEAD:CONTRIBUTING.md
7. [Open a pull request](https://help.github.com/articles/about-pull-requests/)
    with a clear title and description against the `reorganise` branch.
=======
7. [Open a pull request][pr-guide] with a clear title and description against the
   `reorganise` branch.
>>>>>>> 3b3187f7c1be4be7cbb5c20ccf1d0486770e3379:.github/CONTRIBUTING.md

## Code of Conduct

This project has a [Code of Conduct](CODE_OF_CONDUCT.md). Please follow it in all your interactions with the project.


[fork-guide]: https://help.github.com/fork-a-repo/
[rebase-guide]: https://help.github.com/articles/interactive-rebase
[pr-guide]: https://help.github.com/articles/about-pull-requests/
