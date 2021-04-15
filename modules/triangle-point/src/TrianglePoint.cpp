// Copyright 2021 Belik Julia

#include <cmath>
#include "include/TrianglePoint.h"

Triangle::Triangle(std::pair<double, double>  _a, std::pair<double, double> _b, std::pair<double, double> _c) {
    a = _a;
    b = _b;
    c = _c;
}

bool Triangle::isInside(std::pair<double, double>  x) {
    double tmp1, tmp2, tmp3;
    tmp1 = (a.first - x.first) * (b.second - a.second) - (b.first - a.first) * (a.second - x.second);
    tmp2 = (b.first - x.first) * (c.second - b.second) - (c.first - b.first) * (b.second - x.second);
    tmp3 = (c.first - x.first) * (a.second - c.second) - (a.first - c.first) * (c.second - x.second);
    return (((tmp1 > 0) && (tmp2 > 0) && (tmp3 > 0)) || ((tmp1 < 0) && (tmp2 < 0) && (tmp3 < 0)));
}
