#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int table[40000];
int A[20];

int main()
{
    int n; cin >> n;
    rep(i, n) {cin >> A[i];}
    for(int i=0; i<(1<<n+1); i++) {
        int sum=0;
        for(int j=i, k=0; j>0; j>>=1, k++) {if (j&1) {sum+=A[k];}}
        table[sum]++;
    }
    int q; cin >> q;
    rep(i, q) {
        int x; cin >> x;
        printf("%s\n", table[x]?"yes":"no");
    }
}