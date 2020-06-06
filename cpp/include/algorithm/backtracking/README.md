# Backtracking

Backtracking is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems, that incrementally builds candidates to the solutions, and abandons each partial candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

Backtracking can be applied only for problems which admit the concept of a "partial candidate solution" and a relatively quick test of whether it can possibly be completed to a valid solution. It is useless, for example, for locating a given value in an unordered table. When it is applicable, however, backtracking is often much faster than brute force enumeration of all complete candidates, since it can eliminate a large number of candidates with a single test.

### Contents

1. [N queens](#1-n-queens)

---

## 1. N queens

The N queens puzzle is the problem of placing _N_ chess queens on an _N×N_ chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

Read more on [Wikipedia](https://en.wikipedia.org/wiki/Eight_queens_puzzle).

### Usage

```c++
NQueensSolver solver = NQueensSolver(16);   // 16 queens are to be placed

if (solver.can_place_queens()) {    // there is at least 1 way to place the queens
    // get the number of solutions
    size_t num_solutions = solver.num_solutions();
    
    // print the first solution
    solver.print_solution();

    // print all solutions
    solver.print_all_solutions();

    // get a solution as a 2D boolean vector
    Board one_solution = solver.get_solution();

    // get all solutions as a vector of 2D boolean vectors
    std::vector<Board> all_solutions = solver.get_all_solutions();
}
```

**Note**: `Board` is a 2D boolean vector, a type alias for `std::vector<std::vector<bool>>`. A cell that is `true` represents that a queen is placed there, and `false` represents an empty cell.

### Complexity

Time    | Space
--------|-------------------
_O(N!)_ | _O(N<sup>2</sup>)_

where N is the number of queens.
