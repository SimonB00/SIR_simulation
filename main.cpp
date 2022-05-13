#include "Histogram.hpp"
#include "pandemics.hpp"
#include "tables.hpp"
#include <string>
#include <vector>
#include "pandemics.hpp"
#include "StateOfThePandemic.hpp"

int main() {
  int I_0;
  double beta;
  double gamma;
  double n;
  int count;
  std::string risp;
  std::string name;

  std::cout << "How many pandemics do you want to test?" << '\n';
  std::cin >> count;

  for (int i = 0; i < count; ++i) {
    std::cout << "Do you want to use on of the premade pandemics?" << '\n';
    std::cin >> risp;

    if (risp == "yes") {
      std::cout << "Insert the city where the pandemics takes place (Vatican, Bologna, "
                   "NewYork, Riccione, Ferrara, London)"
                << '\n';
      std::cin >> name;
      if (name == "Vatican") {
        Vaticano(I_0, beta, gamma, n);
      } else if (name == "Bologna") {
        Bologna(I_0, beta, gamma, n);
      } else if (name == "NewYork") {
        NewYork(I_0, beta, gamma, n);
      } else if (name == "Riccione") {
        Riccione(I_0, beta, gamma, n);
      } else if (name == "Ferrara") {
        Ferrara(I_0, beta, gamma, n);
      } else if (name == "London") {
        Londra(I_0, beta, gamma, n);
      }

    } else if (risp == "no") {
      std::cout << "Insert I_0: " << '\n';
      std::cin >> I_0;
      std::cout << "Insert beta: " << '\n';
      std::cin >> beta;
      std::cout << "Insert gamma: " << '\n';
      std::cin >> gamma;
      std::cout << "Insert n: " << '\n';
      std::cin >> n;
    }

    std::vector<SotP> pandemic1 = fill(I_0, beta, gamma, n);
      std::vector<table> table1 = fillTable(pandemic1);

      // dailyTable(pandemic1);
      std::cout << ' ' << '\n';
      dailyTable(table1);
      std::cout << ' ' << '\n';

      Histo1D Pand1(pandemic1.size(), table1);
      Pand1.drawhI();
      Pand1.drawhR();
      Pand1.drawhS();
  }
}
