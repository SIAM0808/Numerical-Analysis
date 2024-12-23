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
    double x3, h1, h2, delta1, delta2, a, b, c, discriminant, d;
    int iteration = 0;
    while (maxIter--)
    {
        
         h1 = x1 - x0;
         h2 = x2 - x1;
         delta1 = (f(x1) - f(x0)) / h1;
         delta2 = (f(x2) - f(x1)) / h2;
         a = (delta2 - delta1) / (h1 + h2);
         b = a * h2 + delta2;
         c = f(x2);
         discriminant = sqrt(b * b - 4 * a * c), d;
        if (abs(b + discriminant) > abs(b - discriminant))
        {
            d = b + discriminant;
        }
        else
        {
            d = b - discriminant;
        }
        x3 = x2 - (2 * c) / d;

        if (abs(x3 - x2) < tolerance)
        {
        //     x0 = x1;
        // x1 = x2;
        // x2 = x3;
           break;
        }
        iteration++;
        x0 = x1;
        x1 = x2;
        x2 = x3;
        
    }
     cout << "\nRoot found: " << x3 << " after " << iteration + 1 << " iterations\n";
     cout << "Error: " << fabs(x3 - x2)*100 / x3 << "%" << endl;
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