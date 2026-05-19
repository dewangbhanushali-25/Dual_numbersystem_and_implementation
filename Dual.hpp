#pragma once
#include <iostream>
#include <cmath>


struct Dual{

    double val;
    double der;

    //default constructor
    //
    Dual(double v = 0.0 , double d = 0.0) : val(v), der(d){}

    //overload ADDITION
    Dual operator+(const Dual& other) const{
        return Dual(val + other.val,der + other.der);
    }
    //overload subtraction
    Dual operator-(const Dual& other ) const{
        return Dual(val - other.val,der - other.der);

    }
    // overload multiplication
    //
    Dual operator*(const Dual& other)const {
        return Dual(val * other.val,(der*other.val +val*other.der));



    }

    Dual operator/(const Dual& other)const{
        double denom = other.val * other.val;
        return Dual(val/other.val,(der*other.val-val*other.der)/denom);
    }



};

//overload global functions so we can do sin(dual ) and cos too
//
inline Dual sin(const Dual& x){
    return Dual(std :: sin(x.val),std :: cos(x.val)* x.der);
}

inline Dual cos(const Dual& x){
    return Dual(std:: cos(x.val),-std::sin(x.val)*x.der);
}

inline Dual exp(const Dual& x){
    double ev = std:: exp(x.val);
    return Dual(ev,ev*x.der);
}
