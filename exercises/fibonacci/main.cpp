#include "fibonacci.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: fibonacci <n>\n";
    return 1;
  }

  char *end = nullptr;
  const long n = std::strtol(argv[1], &end, 10);
  if (end == argv[1] || *end != '\0' || n < 0 || n > static_cast<long>(fibonacci::MAX_N))
  {
    std::cerr << "n must be a whole number from 0 to " << fibonacci::MAX_N << "\n";
    return 1;
  }

  std::cout << fibonacci::fib(static_cast<unsigned>(n)) << '\n';
  return 0;
}
