#include "fibonacci.hpp"

namespace fibonacci
{
  namespace
  {
    // Learning tail recursion: the recursive call is the last thing the function does, and the
    // running pair (current, next) is carried in the arguments instead of building up on the stack.
    unsigned long long helper(unsigned n, unsigned long long current, unsigned long long next)
    {
      if (n == 0)
        return current;

      return helper(n - 1, next, current + next);
    }
  }

  unsigned long long fib(unsigned n)
  {
    if (n > MAX_N)
      return 0;

    return helper(n, 0, 1);
  }
}
