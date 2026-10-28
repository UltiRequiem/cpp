#include "../../tests/check.hpp"
#include "fibonacci.hpp"

int main()
{
  CHECK(fibonacci::fib(0) == 0);
  CHECK(fibonacci::fib(1) == 1);
  CHECK(fibonacci::fib(2) == 1);
  CHECK(fibonacci::fib(3) == 2);
  CHECK(fibonacci::fib(4) == 3);
  CHECK(fibonacci::fib(10) == 55);
  CHECK(fibonacci::fib(50) == 12586269025ULL);
  CHECK(fibonacci::fib(93) == 12200160415121876738ULL);

  // beyond what fits in 64 bits
  CHECK(fibonacci::fib(94) == 0);

  // every number is the sum of the two before it
  for (unsigned n = 2; n <= fibonacci::MAX_N; ++n)
    CHECK(fibonacci::fib(n) == fibonacci::fib(n - 1) + fibonacci::fib(n - 2));

  return report();
}
