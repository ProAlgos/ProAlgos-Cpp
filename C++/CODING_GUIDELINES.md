# C++ Coding Guidelines

Most of the sections in these guidelines are adapted from the
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
Only those sections that are relevant to this project have been included here.
You can read the complete guide to know more of the good practises of writing C++ code.

This document is not yet complete.

### Contents
- [Naming](#naming)
  - [General naming rules](#general-naming-rules)
- [Formatting](#formatting)
  - [Tabs vs. Spaces](#tabs-vs-spaces)
  - [Horizontal whitespace](#horizontal-whitespace)
- [Compiling](#compiling)

## Naming

### General naming rules
- Give as descriptive a name as possible, within reason.

- Do not use abbreviations that are ambiguous or unfamiliar to readers outside your project,
and do not abbreviate by deleting letters within a word.

- Certain universally-known abbreviations are OK, such as `i` for an iteration variable and `T` for a template parameter.

#### Good

```C++
int price_count_reader;    // No abbreviation.
int num_errors;            // "num" is a widespread convention.
int num_dns_connections;   // Most people know what "DNS" stands for.
```

#### Bad

```C++
int n;                     // Meaningless.
int nerr;                  // Ambiguous abbreviation.
int n_comp_conns;          // Ambiguous abbreviation.
int wgc_connections;       // Only your group knows what this stands for.
int pc_reader;             // Lots of things can be abbreviated "pc".
int cstmr_id;              // Deletes internal letters.
```

## Formatting

### Tabs vs. Spaces
Use soft tabs that are 4 spaces long. :grin:

### Horizontal whitespace

#### General rules
- Never put trailing whitespace at the end of a line.

- Open braces should always have a space before them.
  ```C++
  void f(bool b) {
      ...
  ```

- Semicolons usually have no space before them.
  ```C++
  int i = 0;
  ```

- Spaces inside braces for braced-init-list are optional. If you use them, put them on both sides!
  ```C++
  int x[] = { 0 };
  int y[] = {0};
  ```

- Spaces around the colon in inheritance and initializer lists.
  ```C++
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
  ```C++
  x = 0;
  ```

- Other binary operators usually have spaces around them, but it's OK to remove spaces around factors.
  Also, parentheses should have no internal padding.
  ```C++
  v = w * x + y / z;
  v = w*x + y/z;
  v = w * (x + z);
  ```

- No spaces separating unary operators and their arguments.
  ```C++
  x = -5;
  ++y;
  z = !y;
  ```
