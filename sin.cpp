// -(x*x *(2*n + 1))/((2*n +3) * (2*n +3) * (2*n +2))

#include <iostream>
#include <iomanip>
#include <math.h>

double Qn(double n, double x){
    return -(x*x *(2*n + 1))/((2*n +3) * (2*n +3) * (2*n +2));
}

int main(){
    double eps = pow(10, -6);
    int a = 0; int b = 4; double h = 0.4;

    double values[10];
    int valuesIndex = 0;
    
    double x = 0;
    while(x <= b){
        int n = 0;

        double An = 0;
        double Anplus = x;
        
        values[valuesIndex] += Anplus;
        An = Anplus;
        
        n++;

        while(abs(An) >= eps){
            Anplus = Qn(n-1, x) * An;
            values[valuesIndex] += Anplus;
            An = Anplus;

            n++;
        }

        std::cout << "x" << valuesIndex << " = " << x << " f(x" << valuesIndex << ") = " << values[valuesIndex] << "\n";

        x += h;
        valuesIndex++;
    }
    return 0;
}