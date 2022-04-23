#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 単純に考えたら N Comb 3 通り ~~ N^3 = (10^4)^3 = 10^12 なので無理
// すでに出た桁は見ない形で枝刈り

const int MAX_N = 1000;
bool PIN[MAX_N];

int main()
{
    fill(PIN, PIN+MAX_N, 0);
    string _, S; cin >> _ >> S;
    rep(n, MAX_N) {
        int v[] = {n/100, (n/10)%10, n%10};
        int match = 0;
        rep(s, S.size()) {
            if (v[match] == S[s]-'0') if (++match==3) {PIN[n]=true; break;}
        }
    }
    int ans=0; rep(i, MAX_N) if (PIN[i]) ans++;
    printf("%d\n", ans);
}