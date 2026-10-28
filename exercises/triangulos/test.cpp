#include "../../tests/check.hpp"
#include "triangulos.hpp"

#include <sstream>

int main()
{
  CHECK(triangulos::classify(60, 60, 60) == "ACUTANGULO");
  CHECK(triangulos::classify(89, 45, 46) == "ACUTANGULO");
  CHECK(triangulos::classify(90, 45, 45) == "RECTANGULO");
  CHECK(triangulos::classify(30, 90, 60) == "RECTANGULO");
  CHECK(triangulos::classify(100, 40, 40) == "OBTUSANGULO");
  CHECK(triangulos::classify(20, 20, 140) == "OBTUSANGULO");

  std::istringstream in("3\n60 60 60\n90 45 45\n100 40 40\n");
  std::ostringstream out;
  triangulos::run(in, out);
  CHECK(out.str() == "ACUTANGULO\nRECTANGULO\nOBTUSANGULO\n");

  // fewer lines than announced: answer the ones that are there instead of looping on bad input
  std::istringstream short_in("5\n60 60 60\n");
  std::ostringstream short_out;
  triangulos::run(short_in, short_out);
  CHECK(short_out.str() == "ACUTANGULO\n");

  return report();
}
