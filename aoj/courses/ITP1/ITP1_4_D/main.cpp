#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int a[10000];

int main()
{
    long int N, min=1000000, max=-1000000, sum=0;
    cin >> N;
    rep(i, N) {cin >> a[i];}
    rep(i, N) {
        if (min > a[i]) {min = a[i];}
        if (max < a[i]) {max = a[i];}
        sum += a[i];
    }
    cout << min << " " << max << " " << sum << endl;
}