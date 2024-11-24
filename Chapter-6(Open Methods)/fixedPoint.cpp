#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 10000;
double f(double x) {
    return exp(-x) - x; 
}
double g(double x){
    return exp(-x);
}
void fixed(double x0){
    double x;
    int it=0;
    while(maxIter--){
        it++;
        x = g(x0);
        if(fabs(f(x))<tolerance){
            break;
        }
        x0 = x;
    }
    cout << "Approximate root: " << x << endl;
    cout << "Error: " << fabs((x-x0)/x)*100 << endl;
    cout << "Iterations: " << it << endl;
}
int main(){
    double a;
    cin >> a ;
    fixed(a);
    return 0;
}