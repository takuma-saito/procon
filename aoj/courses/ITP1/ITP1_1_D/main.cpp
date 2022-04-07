#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int S;
    cin >> S;
    cout << S/3600 << ":" << (S/60)%60 << ":" << S%60 << endl;
}