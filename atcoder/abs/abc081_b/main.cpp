#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000
int A[200];

int main()
{
    int N, ans=INF;
    cin >> N;
    rep(i, N) {cin >> A[i];}
    rep(i, N) {
        int x = (A[i]&-A[i]), sum=0;
        while (x > 0) { x >>= 1; sum++; }
        if (ans > sum) {ans=sum;}
    }
    cout << ans-1 << endl;
}