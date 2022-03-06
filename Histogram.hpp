#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include "StateOfThePandemic.hpp"
#include "approx.hpp"
#include <algorithm>
#include <iostream>
#include <vector>



class Histo1D {
private:
  std::vector<table> bins{};
  double xlow_;
  double xup_;

public:
  Histo1D(double xup, std::vector<table> vector)
      : bins{vector}, xlow_{0}, xup_{xup} {}

  double maxI() {
    auto it = bins.begin();
    int size = bins.size();
    std::vector<int> inf;

    for (int i = 0; i < size; ++i) {
      inf.push_back(it->I);
      ++it;
    }

    std::sort(inf.begin(), inf.end(), std::greater<int>());
    double result = *inf.begin();

    return result;
  }

  double maxR() {
    auto it = bins.begin();
    int size = bins.size();
    std::vector<int> rec;

    for (int i = 0; i < size; ++i) {
      rec.push_back(it->R);
      ++it;
    }

    std::sort(rec.begin(), rec.end(), std::greater<int>());
    double result = *rec.begin();

    return result;
  }

  double maxS() {
    auto it = bins.begin();
    int size = bins.size();
    std::vector<int> suc;

    for (int i = 0; i < size; ++i) {
      suc.push_back(it->S);
      ++it;
    }

    std::sort(suc.begin(), suc.end(), std::greater<int>());
    double result = *suc.begin();

    return result;
  }

  void drawhI() {
    auto it = bins.begin();
    double scale;

    if (maxI() <= 100) {
      scale = 1;
    } else if (maxI() > 100 && maxI() <= 1000) {
      scale = maxI() / 100;
    } else if (maxI() > 1000 && maxI() <= 10000) {
      scale = maxI() / 150;
    } else if (maxI() > 10000) {
      scale = maxI() / 180;
    }

    std::cout << "Infected:" << '\n';
    for (int day = xlow_; day < xup_; ++day) {
      if (day < 10) {
        std::cout << "Day " << day << "    |";
      } else if (day >= 10 && day < 100) {
        std::cout << "Day " << day << "   |";
      } else if (day >= 100) {
        std::cout << "Day " << day << "  |";
      }

      if (approx((it->I) / scale) == 0 && (it->I) / scale > 0) {
        std::cout << "\u001b[31m" << '#';
        std::cout << "\u001b[37m" << ' ';
      }

      for (int j = 1; j <= approx((it->I) / scale); ++j) {
        std::cout << "\u001b[31m" << '#';
      }
      it++;
      std::cout << "\u001b[37m" << ' ' << '\n';
    }
    std::cout << "\u001b[37m" << ' ' << '\n';
  }

  void drawhS() {
    auto it = bins.begin();
    double scale;

    if (maxS() <= 100) {
      scale = 1;
    } else if (maxS() > 100 && maxS() < 1000) {
      scale = maxS() / 100;
    } else if (maxS() > 1000 && maxS() < 10000) {
      scale = maxS() / 150;
    } else if (maxS() > 10000) {
      scale = maxS() / 180;
    }

    std::cout << "Susceptibles:" << '\n';
    for (int day = xlow_; day < xup_; ++day) {
      if (day < 10) {
        std::cout << "Day " << day << "    |";
      } else if (day >= 10 && day < 100) {
        std::cout << "Day " << day << "   |";
      } else if (day >= 100) {
        std::cout << "Day " << day << "  |";
      }

      if (approx((it->S) / scale) == 0 && (it->S) / scale > 0) {
        std::cout << "\u001b[33m" << '#';
        std::cout << "\u001b[37m" << ' ';
      }

      for (int j = 1; j <= approx((it->S) / scale); ++j) {
        std::cout << "\u001b[33m" << '#';
      }
      it++;
      std::cout << "\u001b[37m" << ' ' << '\n';
    }
    std::cout << "\u001b[37m" << ' ' << '\n';
  }

  void drawhR() {
    auto it = bins.begin();
    double scale;

    if (maxR() <= 100) {
      scale = 1;
    } else if (maxS() > 100 && maxS() < 1000) {
      scale = maxS() / 100;
    } else if (maxS() > 1000 && maxS() < 10000) {
      scale = maxS() / 150;
    } else if (maxS() > 10000) {
      scale = maxS() / 180;
    }

    std::cout << "Recovered or dead:" << '\n';
    for (int day = xlow_; day < xup_; ++day) {
      if (day < 10) {
        std::cout << "Day " << day << "    |";
      } else if (day >= 10 && day < 100) {
        std::cout << "Day " << day << "   |";
      } else if (day >= 100 && day < 1000) {
        std::cout << "Day " << day << "  |";
      }

      if (approx((it->R) / scale) == 0 && (it->R) / scale > 0) {
        std::cout << "\u001b[32m" << '#';
        std::cout << "\u001b[37m" << ' ';
      }

      for (int j = 1; j <= approx((it->R) / scale); ++j) {
        std::cout << "\u001b[32m" << '#';
      }
      ++it;
      std::cout << "\u001b[37m" << ' ' << '\n';
    }
    std::cout << "\u001b[37m" << ' ' << '\n';
  }
};

#endif