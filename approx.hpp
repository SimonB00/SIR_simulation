#ifndef APPROX_HPP
#define APPROX_HPP

int approx(double n){
    int integerpart = n;
    int result;

    if(n - integerpart >= 0.5){
        result = (integerpart + 1);
    } else {
        result = integerpart;
    }

    return result;
}

#endif