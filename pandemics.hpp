#ifndef PANDEMICS_HPP
#define PANDEMICS_HPP

inline void Vatican(int& a, double& b, double& c, double& d){
    // R0 = 0.77
    
    a = 10; 
    b = 0.0005;
    c = 0.4;
    d = 618;
}

inline void Bologna(int& a, double& b, double& c, double& d){
    // R0 = 2.4
    
    a = 30; 
    b = 0.000003;
    c = 0.5;
    d = 400000;
}

inline void NewYork(int& a, double& b, double& c, double& d){
    // R0 = 1.57
    
    a = 1000; 
    b = 0.00000009333;
    c = 0.5;
    d = 8399000;
}

inline void Riccione(int& a, double& b, double& c, double& d){
    // R0 = 2.5
    
    a = 60;
    b = 0.00005;
    c = 0.7;
    d = 35000;
}
 
inline void Ferrara(int& a, double& b, double& c, double& d){
    // R0 = 1.155

    a = 1;
    b = 0.000007;
    c = 0.8;
    d = 132000;
}

inline void London(int& a, double& b, double& c, double& d){
    // R0 = 4.41
 
    a = 200;
    b = 0.0000002;
    c = 0.4;
    d = 8825000;
}

#endif
