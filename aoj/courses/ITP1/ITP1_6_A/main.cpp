#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int a[100];

int main()
{
    int n;
    cin >> n;
    rep(i, n) {cin >> a[i];}
    rep(i, n) {cout << a[n-i-1] << (i!=n-1?" ":"");}
    cout << endl;

}