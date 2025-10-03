#include "point.h"

std::ostream& operator<<(std::ostream& os, Point const& p) {
  return os << p.x << " " << p.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
  return is >> p.x >> p.y;
}