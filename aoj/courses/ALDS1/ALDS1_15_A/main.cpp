#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, ans = 0; cin >> n;
    for(int i: {25, 10, 5, 1}) { ans+=n/i; n=n%i;}
    cout << ans << endl;
}