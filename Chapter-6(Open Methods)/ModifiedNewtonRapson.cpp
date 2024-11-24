#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 100;
double f(double x) {
    return pow(x,10) - 1; 
}
double f_prime(double x){
    return 10*pow(x,9);
}
void ModifiedNewtonRapson(double x0){
    double x1;
    int times=0;
    while(maxIter--){
        times++;
        x1 = x0 - (f(x0)*f_prime(x0))/((f_prime(x0)*f_prime(x0))  - (f(x0)*f_prime(x0)));
        if(abs(f(x1))<tolerance){
            break;
        }
        x0 = x1;
    }
    cout << "Approximate root: " << x1 << endl;
    cout << "Error: " << fabs((x1-x0)/x1)*100 << "%" <<  endl;
    cout << "Iterations: " << times << endl;
}
int main(){
    double x0 ;
    
    cin >> x0 ;
    ModifiedNewtonRapson(x0);
    return 0;
}