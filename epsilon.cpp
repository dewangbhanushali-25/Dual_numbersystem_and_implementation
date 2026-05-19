#include <iostream>
#include <cmath>


struct Dual{
    double real ;
    double dual; // eplsion dual number

    Dual operator*(const Dual& other)const{
        return Dual{
            real*other.real,
            (real*other.dual)+(dual * other.real)
        };
    }



    Dual operator+(const Dual& other)const {
        return Dual{real + other.real , dual + other.dual};
    }
};


Dual d_sin(const Dual& x){
    return Dual{std::sin(x.real),std::cos(x.real)*x.dual};
}
int main(){
    Dual x {2.0 ,1.0};
    Dual result = (x*x) +d_sin(x);
    std :: cout << "value of f(2)" << result.real << std ::endl;
    std ::cout << "exact derviation f'(2) :" << result.dual << std::endl;
    return 0 ;


}
