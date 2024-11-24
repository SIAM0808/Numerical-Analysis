#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 100;
double f(double x) {
    return x*x*x - 1; 
}
void bisection(double a, double b){
    double c;
    int it=0;
    while(abs(b-a)>tolerance && maxIter--){
        c = (a+b)/2;
        if(f(c)==0){
            break;
        }
        if(f(c)*f(a)<0){
            b = c;
        }else{
            a = c;
        }
        it++;
    }
    cout << "Approximate root: " << c << endl;
    cout << "Error: " << abs(b-a) << endl;
    cout << "Iterations: " << it << endl;
    
}
int main(){
    double x0 ;
    double x1;
    cin >> x0 >> x1;
    bisection(x0,x1);
    return 0;
}