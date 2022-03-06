#ifndef TABLES_HPP
#define TABLES_HPP

#include "Histogram.hpp"

void dailyTable(std::vector<SotP> vec){
    int size = vec.size();
    auto it = vec.begin();
    
    for (int i = 0; i < size; ++i) {
        std::cout << "Day " << i << ":";
        std::cout << "   Susceptible = " << it->S;
        std::cout << "   Infected = " << it->I;
        std::cout << "   Recovered or dead = " << it->R << '\n';
        ++it;
    }
}

void dailyTable(std::vector<table> vec){
    int size = vec.size();
    auto it = vec.begin();
    
    for (int i = 0; i < size; ++i) {
        std::cout << "Day " << i << ":";
        std::cout << "   Susceptible = " << it->S;
        std::cout << "   Infected = " << it->I;
        std::cout << "   Recovered or dead = " << it->R << '\n';
        ++it;
    }
} 

auto fill(double I_0, double beta_, double gamma_, double n){
    SotP Yesterday{ n - I_0, I_0, 0};
    std::vector<SotP> State{ Yesterday };  
    SotP Today;
    int durata = n - I_0;

    for (int time = 0; durata !=0; ++time) {
        
        Today.S = Yesterday.S - beta_ * Yesterday.I * Yesterday.S;
        Today.I = Yesterday.I + beta_ * Yesterday.I * Yesterday.S - gamma_ * Yesterday.I;
        Today.R = Yesterday.R + gamma_ * Yesterday.I;

        State.push_back(Today);
    
        Yesterday = Today;
        durata = Yesterday.I;

        if(time == 200){
            break;
        }
    }
    return State;
}

auto fillTable(std::vector<SotP> state){
    auto it = state.begin();
    int size = state.size();
    table today;
    std::vector<table> Table;

    for(int i = 0; i < size; ++i){
        today.S = approx(it->S);
        today.I = approx(it->I);
        today.R = it->R;

        Table.push_back( {today.S, today.I, today.R} );

        ++it;
    }

    return Table;
}

#endif