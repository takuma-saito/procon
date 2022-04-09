#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    cout << fixed << std::setprecision(20);
    int a, b, angle; cin >> a >> b >> angle;
    double S = a*b*sin(2*M_PI*angle/360.0)/2.0;
    cout << S << endl;
    cout << sqrt(pow(a, 2)+pow(b, 2)-2*a*b*cos(2*M_PI*angle/360.0))+a+b << endl;
    cout << ((S*2)/a) << endl;
}