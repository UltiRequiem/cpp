#include "triangulos.hpp"

#include <istream>
#include <ostream>

namespace triangulos
{
  std::string classify(int a1, int a2, int a3)
  {
    if (a1 < 90 && a2 < 90 && a3 < 90)
      return "ACUTANGULO";
    if (a1 == 90 || a2 == 90 || a3 == 90)
      return "RECTANGULO";

    return "OBTUSANGULO";
  }

  void run(std::istream &in, std::ostream &out)
  {
    int n = 0;
    in >> n;

    for (int i = 0; i < n; ++i)
    {
      int a1 = 0, a2 = 0, a3 = 0;
      if (!(in >> a1 >> a2 >> a3))
        break;

      out << classify(a1, a2, a3) << '\n';
    }
  }
}
