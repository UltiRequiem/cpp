#ifndef TRIANGULOS_HPP
#define TRIANGULOS_HPP

#include <iosfwd>
#include <string>

namespace triangulos
{
  // "ACUTANGULO" if all three angles are below 90, "RECTANGULO" if one is exactly 90,
  // otherwise "OBTUSANGULO".
  std::string classify(int a1, int a2, int a3);

  // Reads `n` and then `n` lines of three angles, writes one classification per line.
  void run(std::istream &in, std::ostream &out);
}

#endif
