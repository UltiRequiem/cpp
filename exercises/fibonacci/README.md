# Fibonacci, with tail recursion

The first exercise from the recursion lesson: the n-th Fibonacci number, written so the recursive call is the
last thing the function does (a *tail call*) and the running values travel in the arguments.

```sh
cmake -S . -B build && cmake --build build
./build/fibonacci 10     # 55
```

- `fib(0) = 0`, `fib(1) = 1`, `fib(2) = 1`, `fib(3) = 2`, ...
- Uses `unsigned long long`, so the largest answer that fits is `fib(93)`. Bigger values return 0.

The first version had `fib(0)` returning 1 and used `int`, which overflows at `fib(47)`. Both are fixed
and covered by [`test.cpp`](./test.cpp).
