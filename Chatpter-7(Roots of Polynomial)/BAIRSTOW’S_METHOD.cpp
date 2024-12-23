#include <iostream>
#include <math.h>
using namespace std;
double tolerance = 0.000001;
int maxIter = 100;
double f(double x)
{
    return x * x * x - 13 * x - 12;
}
void muller(double x0, double x1, double x2)
{
    
}
int main()
{
    double x0;
    double x1;
    double x2;
    cin >> x0 >> x1 >> x2;
    muller(x0, x1, x2);
    return 0;
}