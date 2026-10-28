#ifndef CHECK_HPP
#define CHECK_HPP

#include <iostream>

// Plain checks instead of assert(), which is compiled out in release builds.
// Use CHECK(...) in a test, then `return report();` from main.
inline int &failures()
{
  static int count = 0;
  return count;
}

#define CHECK(condition)                                                                \
  do                                                                                    \
  {                                                                                     \
    if (!(condition))                                                                   \
    {                                                                                   \
      std::cerr << __FILE__ << ":" << __LINE__ << ": CHECK(" #condition ") failed\n";   \
      ++failures();                                                                     \
    }                                                                                   \
  } while (false)

inline int report()
{
  if (failures() != 0)
  {
    std::cerr << failures() << " check(s) failed\n";
    return 1;
  }
  std::cout << "all checks passed\n";
  return 0;
}

#endif
