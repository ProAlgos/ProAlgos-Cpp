# Dynamic programming

Dynamic programming (also known as dynamic optimization) is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions. The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space. (Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup.) The technique of storing solutions to subproblems instead of recomputing them is called "memoization".

Dynamic programming algorithms are often used for optimization. A dynamic programming algorithm will examine the previously solved subproblems and will combine their solutions to give the best solution for the given problem.

### Contents

1. [Matrix chain multiplication](#1-matrix-chain-multiplication)

---

## 1. Matrix chain multiplication

Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.

There are many options available because matrix multiplication is associative. In other words, no matter how the product is parenthesized, the result obtained will remain the same. For example, for four matrices A, B, C, and D, we would have:

_((AB)C)D = (A(BC))D = (AB)(CD) = A((BC)D) = A(B(CD))_

However, the order in which the product is parenthesized affects the number of simple arithmetic operations needed to compute the product, that is the computational complexity. For example, if A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix, then

* computing _(AB)C_ needs (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations, while
* computing _A(BC)_ needs (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Clearly the first method is more efficient. With this information, the problem statement can be refined as "how to determine the optimal parenthesization of a product of n matrices?"

### Usage

```c++
MatrixChainMultiplier chain_multiplier = MatrixChainMultiplier({40, 30, 20, 10, 30});

// ull is a type alias for `unsigned long long`
ull optimal_cost = chain_multiplier.optimal_cost();     // 30000

std::string optimal_parenthesization = chain_multiplier.optimal_parenthesization();
// ((A(BC))D)
```

### Complexity

Time               | Space
-------------------|-------------------
_O(N<sup>3</sup>)_ | _O(N<sup>2</sup>)_

where N is the number of matrices.
