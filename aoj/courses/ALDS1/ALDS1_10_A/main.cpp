#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n; cin >> n;
    int prev = 0, curr=1;
    rep(i, n) {int x = curr; curr += prev; prev = x;}
    cout << curr << endl;
}