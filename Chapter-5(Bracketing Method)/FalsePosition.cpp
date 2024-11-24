#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 10000;
double f(double x) {
    return x*x*x - 1; 
}
void FalsePosition(double x0, double x1){
    double x ;
    int it=0;
    while(abs(x1-x0)>tolerance && maxIter--){
        x = (x1*f(x0) - x0*f(x1))/(f(x0)-f(x1));
        if(f(x)*f(x0)<0){
            x1 = x;
        }else{
            x0 = x;
        }
        it++;
    }
    cout << "Approximate root: " << x << endl;
    cout << "Error: " << fabs(f(x)) << endl;
    cout << "Iterations: " << it << endl;
}
int main(){
    double x0 ;
    double x1;
    cin >> x0 >> x1;
    FalsePosition(x0,x1);
    return 0;
}