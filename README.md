# C++

[![CI](https://github.com/UltiRequiem/cpp/actions/workflows/ci.yaml/badge.svg)](https://github.com/UltiRequiem/cpp/actions/workflows/ci.yaml)

I'm currently in college (studying Computer Science), and it looks like the only languages that will be taught here are C++ and Java. While I wasn't initially interested in learning these languages, I'm starting to like C++. I'm actually excited to get back to Java. I think that because of my real-world experience building cool stuff with JavaScript and other more mainstream languages, I was a bit too closed off to studying C++. But it's actually fun.

This repo is where I keep the C++ exercises from that course, one folder each, with its own tests.

## Exercises

| Exercise | What it is | Topics |
|---|---|---|
| [fibonacci](./exercises/fibonacci) | the n-th Fibonacci number | recursion, tail calls, integer overflow |
| [triangulos](./exercises/triangulos) | classify triangles by their angles (judge problem, in Spanish) | reading input, `std::string`, splitting logic from I/O |

## Build, run and test

Needs a C++17 compiler and [CMake](https://cmake.org) 3.14 or newer.

```sh
cmake -S . -B build
cmake --build build
cd build && ctest --output-on-failure
```

Every exercise becomes a program in `build/` named after its folder:

```sh
./build/fibonacci 10
printf '2\n60 60 60\n90 45 45\n' | ./build/triangulos
```

## Add an exercise

1. Create `exercises/<name>/` with `<name>.cpp` (+ `<name>.hpp`), `main.cpp` and `test.cpp`, and a short `README.md`.
2. Add `add_exercise(<name>)` at the bottom of [CMakeLists.txt](./CMakeLists.txt).
3. Write tests with `CHECK(...)` from [tests/check.hpp](./tests/check.hpp) and end with `return report();`.

Keep the logic in the `<name>.cpp` file and only the input and output in `main.cpp`, so the logic can be tested.

## License

MIT, see [LICENSE](./LICENSE).
