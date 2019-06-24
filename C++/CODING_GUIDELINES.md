# C++ Coding Guidelines

Most of the sections in these guidelines are adapted from the [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) and the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
Only those sections that are relevant to this project have been included here.

**This document is a work in progress.**

## Contents

- [Naming](#naming)
  - [General naming rules](#general-naming-rules)
  - [File names](#file-names)
  - [Type names](#type-names)
  - [Variable names](#variable-names)
  - [Constant names](#constant-names)
  - [Function names](#function-names)
  - [Enumerator names](#enumerator-names)
- [Formatting](#formatting)
  - [Tabs vs. Spaces](#tabs-vs-spaces)
  - [Horizontal whitespace](#horizontal-whitespace)
- [Functions](#functions)
  - [Parameter passing](#parameter-passing)

## Naming

### General naming rules

- Give as descriptive a name as possible, within reason.

- Do not use abbreviations that are ambiguous or unfamiliar to readers outside your project,
and do not abbreviate by deleting letters within a word.

- Certain universally-known abbreviations are OK, such as `i` for an iteration variable and `T` for a template parameter.

#### Good

```cpp
int price_count_reader;    // No abbreviation.
int num_errors;            // "num" is a widespread convention.
int num_dns_connections;   // Most people know what "DNS" stands for.
```

#### Bad

```cpp
int n;                     // Meaningless.
int nerr;                  // Ambiguous abbreviation.
int n_comp_conns;          // Ambiguous abbreviation.
int wgc_connections;       // Only your group knows what this stands for.
int pc_reader;             // Lots of things can be abbreviated "pc".
int cstmr_id;              // Deletes internal letters.
```

### File names and locations

- File and directory names should be all lowercase, with word separators (such as dashes and spaces) replaced with an underscore `_`.
- All source files should be located in `include/<algorithm or data_structure>/<type>` and have the extension `.hpp`.
- All unit test files should be located in `test/<algorithm or data_structure>/<type>` and have the extension `.cpp`.

#### Example

- Source file: `lowest_common_subsequence.hpp` in `include/algorithm/string`
- Unit test file: `lowest_common_subsequence.cpp` in `test/algorithm/string`

### Type names

The names of all types - **classes**, **structs**, **type aliases** and **enums** - have the same naming convention: they should start with a capital letter and have a capital letter for each new word, with no underscores (Pascal case).

#### Examples

```cpp
// classes and structs
class UrlTable { ... };
class UrlTableTester { ... };
struct UrlTableProperties { ... };

// typedefs
typedef hash_map<UrlTableProperties *, string> PropertiesMap;

// using aliases
using PropertiesMap = hash_map<UrlTableProperties *, string>;

// enums
enum UrlTableErrors { ... };
```

### Variable names

The names of variables (including function parameters) and data members are all lowercase, with underscores between words.

#### Examples

`table_name`, `num_dns_connections`, `left_child`.

### Constant names

Variables declared `const` or `constexpr`, and whose value is fixed for the duration of the program, are all uppercase, with underscores between words. All such variables with static storage duration (i.e. statics and globals) should be named this way.

#### Examples

```cpp
const double PI = 3.14159265;
const int MAX_BOARD_SIZE = 16;
```

### Function names

- Function names follow the same rules as those for variable names: all lowercase with underscores between words.
- Accessors (get funtions) should have the same name as the variable (eg. `tree.root()`), and mutators (set functions) should start with `set_` (eg. `tree.set_root(new_root)`).

#### Examples

```cpp
add_table_entry()
is_reversable()
delete_url()
```

### Enumerator names

Enumerators should be named like constants (eg. `ENUM_NAME`). Note that the enumeration name (name of the `enum`) is a type, and should therefore be named using Pascal case, as mentioned under [Type names](#type-names).

#### Examples

```cpp
enum UrlTableErrors {
    OK,
    OUT_OF_MEMORY,
    MALFORMED_INPUT
};

enum TraversalOrder: short {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};
```

## Formatting

### Tabs vs. Spaces

Use soft tabs that are 4 spaces long.

### Horizontal whitespace

#### General rules

- Never put trailing whitespace at the end of a line.

- Open braces should always have a space before them.

  ```cpp
  void f(bool b) {
      ...
  ```

- Semicolons usually have no space before them.

  ```cpp
  int i = 0;
  ```

- Spaces inside braces for braced-init-list are optional. If you use them, put them on both sides!

  ```cpp
  int x[] = { 0 };
  int y[] = {0};
  ```

- Spaces around the colon in inheritance and initializer lists.

  ```cpp
  class Foo : public Bar {
      public:
          // For inline function implementations, put spaces between the braces
          // and the implementation itself.
          Foo(int b) : Bar(), baz_(b) {}  // No spaces inside empty braces.
          void Reset() { baz_ = 0; }      // Spaces separating braces from implementation.
          ...
  }
  ```

#### Operators

- Assignment operators always have spaces around them.

  ```cpp
  x = 0;
  ```

- Other binary operators usually have spaces around them, but it's OK to remove spaces around factors.
  Also, parentheses should have no internal padding.

  ```cpp
  v = w * x + y / z;
  v = w*x + y/z;
  v = w * (x + z);
  ```

- No spaces separating unary operators and their arguments.

  ```cpp
  x = -5;
  ++y;
  z = !y;
  ```

## Functions

- “Package” meaningful operations as carefully named functions.
- Keep functions short and simple.
- A function should perform a single logical operation.
- Use a lambda when a function won’t do (to capture local variables, or to write a local function).

### Parameter passing

For input parameters, pass cheaply-copied types by value and others by reference to `const`.

#### Good

```cpp
void f1(const string& s);  // pass by reference to const; always cheap

void f2(int x);            // unbeatable
```

#### Bad

```cpp
void f3(string s);         // potentially expensive

void f4(const int& x);     // overhead on access in f4()
```
