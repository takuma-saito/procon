#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b;
    cin >> a >> b;
    cout << ((a % 2 == 1) && (b % 2 == 1) ? "Odd" : "Even") << endl;
}