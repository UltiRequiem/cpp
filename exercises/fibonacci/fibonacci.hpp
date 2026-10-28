#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

namespace fibonacci
{
  // The largest n whose Fibonacci number fits in an unsigned long long.
  constexpr unsigned MAX_N = 93;

  // n-th Fibonacci number: fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2, ...
  // Uses tail recursion. Larger n than MAX_N would overflow, so it returns 0 for those.
  unsigned long long fib(unsigned n);
}

#endif
