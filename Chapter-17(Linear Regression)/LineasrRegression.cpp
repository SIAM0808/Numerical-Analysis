#include <bits/stdc++.h>
using namespace std;

#define d double

d mean(vector<d> &x) {
    d sum = 0;
    for (auto i : x) {
        sum += i;
    }
    return sum / x.size();
}

void lr(vector<d> &x, vector<d> &y, d &m, d &c) {
    if (x.size() != y.size() || x.empty()) {
        cerr << "Error: x and y must have the same non-zero size." << endl;
        return;
    }

    d mean_x = mean(x);
    cerr << "Mean of x: " << mean_x << endl;
    d mean_y = mean(y);
    cerr << "Mean of y: " << mean_y << endl;

    d xi_yi_sum = 0, xi_sq_sum = 0;

    for (size_t i = 0; i < x.size(); i++) {
        xi_yi_sum += x[i] * y[i];
        xi_sq_sum += x[i] * x[i];
    }
    cerr << "xi_yi_sum: " << xi_yi_sum << endl;
    cerr << "xi_sq_sum: " << xi_sq_sum << endl;
    d xi_sum = 0, yi_sum = 0;
    for (auto i : x) xi_sum += i;
    for (auto i : y) yi_sum += i;

    cerr << "xi_sum: " << xi_sum << endl;
    cerr << "yi_sum: " << yi_sum << endl;

    m = (xi_yi_sum - (xi_sum * yi_sum) / x.size()) /
        (xi_sq_sum - (xi_sum * xi_sum) / x.size());
    c = mean_y - (m * mean_x);

    cout << "Slope: " << m << endl;
    cout << "Constant: " << c << endl;
}

int32_t main() {
    cout << "Enter the set of [x, y]: " << endl;
    vector<d> x, y;
    cout << "Number of sets: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        d a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    d slope, constant;
    lr(x, y, slope, constant);

    return 0;
}
