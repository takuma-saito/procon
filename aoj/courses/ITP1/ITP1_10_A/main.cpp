#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    cout << fixed << std::setprecision(20);
    double x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << sqrt(pow((x1-x2), 2)+pow((y1-y2), 2)) << endl;
}