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

  std::cout << "Quante pandemie vuoi testare?" << '\n';
  std::cin >> count;

  for (int i = 0; i < count; ++i) {
    std::cout << "Vuoi usare una pandemia predefinita?" << '\n';
    std::cin >> risp;

    if (risp == "si") {
      std::cout << "Inserisci il luogo della pandemia (Vaticano, Bologna, "
                   "NewYork, Riccione, Ferrara, Londra)"
                << '\n';
      std::cin >> name;
      if (name == "Vaticano") {
        Vaticano(I_0, beta, gamma, n);
      } else if (name == "Bologna") {
        Bologna(I_0, beta, gamma, n);
      } else if (name == "NewYork") {
        NewYork(I_0, beta, gamma, n);
      } else if (name == "Riccione") {
        Riccione(I_0, beta, gamma, n);
      } else if (name == "Ferrara") {
        Ferrara(I_0, beta, gamma, n);
      } else if (name == "Londra") {
        Londra(I_0, beta, gamma, n);
      }

    } else if (risp == "no") {
      std::cout << "Inserire I_0: " << '\n';
      std::cin >> I_0;
      std::cout << "Inserire beta: " << '\n';
      std::cin >> beta;
      std::cout << "Inserire gamma: " << '\n';
      std::cin >> gamma;
      std::cout << "Inserire n: " << '\n';
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