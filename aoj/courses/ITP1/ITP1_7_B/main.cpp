#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 301
int comb[MAX_N];

int main()
{
    while(true) {
        int n, x; cin >> n >> x;
        fill(comb, comb+MAX_N, 0);
        if (n == 0 && x == 0) {break;}
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                for(int k=j+1; k<=n; k++) {
                    comb[i+j+k]++;
                }
            }
        }
        cout << comb[x] << endl;
    }
}