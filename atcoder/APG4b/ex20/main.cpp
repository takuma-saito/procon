#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N_MAX 50
array<vector<int>, N_MAX> children;
int ans[N_MAX];

int dfs(int i) {
    int sum = 1;
    for(auto child: children[i]) { sum += dfs(child); }
    ans[i] = sum;
    return sum;
}

int main()
{
    int N;
    cin >> N;
    rep(i, N-1) {
        int p;
        cin >> p;
        children[p].push_back(i+1);
    }
    dfs(0);
    rep(i, N) {cout << ans[i] << endl;}
}