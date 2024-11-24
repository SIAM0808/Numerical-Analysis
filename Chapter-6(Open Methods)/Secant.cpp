#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 100;
double f(double x) {
    return pow(x,10) - 1; 
}
void secant(double x0, double x1){
    double x ;
    int it=0;
    while(abs(x1-x0)>tolerance && maxIter--){
        x = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
        x0 = x1;
        x1 = x;
        it++;
    }
    cout << "Approximate root: " << x << endl;
    cout << "Error: " << abs(x1-x0) << endl;
    cout << "Iterations: " << it << endl;
}
int main(){
    double x0 ;
    double x1;
    cin >> x0 >> x1;
    secant(x0,x1);
    return 0;
}