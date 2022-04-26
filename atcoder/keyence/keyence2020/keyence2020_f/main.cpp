#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_H = 10;
const int MAX_W = 10;
const int MOD_HASH = 100000007;
const int MOD = 998244353;
int H, W; int A[MAX_H][MAX_W]; // W:0 B:1

int main()
{
    cin >> H >> W;
    rep(h, H) {
        string s; cin >> s;
        rep(w, W) A[h][w] = s[w] == '#' ? 1 : 0;
    }
    set<ll> st;
    for(int h=0; h<(1<<H); h++) {
        for (int w=0; w<(1<<W); w++) {
            ll hash = 0;
            for(int i=0; i<H; i++) {
                for (int j=0; j<W; j++) {
                    int v = A[i][j]^(h>>i&1)^(w>>j&1);
                    hash = (hash<<1 | v) % MOD_HASH;
                }
            }
            st.insert(hash);
        }
    }
    printf("%d\n", st.size() % MOD); // TODO: st.size の型
}