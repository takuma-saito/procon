#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_D = 1e9;
const int MAX_N = 1e5;
int D, N, M; vector<int> S;

// 環状線上の店舗をソートした上で店舗を 2 分探索する
// 環状線に沿って並んでいるため本店は 0 の位置と d の位置の 2 つ置くことに注意する

int main()
{
    cin >> D >> N >> M;
    S.push_back(0); S.push_back(D); N--;
    while(N--) {int x; cin >> x; S.push_back(x);}
    sort(S.begin(), S.end());
    int sum=0;
    rep(i, M) {
        int k; cin >> k;
        auto it = lower_bound(S.begin(), S.end(), k);
        sum += min(abs(*it-k), abs(*(it-1)-k));
    }
    printf("%d\n", sum);
}