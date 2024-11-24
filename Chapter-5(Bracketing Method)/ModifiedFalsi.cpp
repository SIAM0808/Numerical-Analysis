#include<bits/stdc++.h>
using namespace std;
double tolerance = 0.0001;
int maxIter = 10000;
double f(double x) {
    return pow(x,10) - 1; 
}
bool check(double x, double y){
    return (f(x)*f(y)<0)?true:false;
}
void ModifiedFalsi(double b, double a){
    int it;
    double x;
    int r=0,l=0;
    while(abs(a-b)>tolerance && maxIter--){
        x = (a*f(b) - b*f(a))/(f(b)-f(a));
        if(f(x)*f(a)<0){
            l=0;
            r++;
            b = x;
            if(r>1){
                if(check(a/2,b)){
                    a /= 2;
                }
            }
        }else{
            r=0;
            l++;
            a = x;
            if(l>1){
                if(check(a,b/2)) b/= 2;
            }
        }
        it++;
    }
    cout << "Approximate root: " << x << endl;
    cout << "Error: " << fabs(f(x)) << endl;
    cout << "Iterations: " << it << endl;
}
int main(){
    double b ;
    double a;
    cin >> b >> a;
    ModifiedFalsi(b,a);
    return 0;
}