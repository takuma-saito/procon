#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b;
    cout << fixed << std::setprecision(20);
    cin >> a >> b;
    cout << (a/b) << " " << (a%b) << " " << (double(a)/b) << endl;
}