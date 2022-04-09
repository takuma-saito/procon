#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, p; cin >> n >> p;
    queue<pair<string, int>> que;
    rep(i, n) {string s; int t; cin >> s >> t; que.push({s, t});}
    int time=0;
    while(!que.empty()) {
        auto [s, t] = que.front(); que.pop();
        if (t <= p) {
            time += t;
            cout << s << " " << time << endl;
        } else {
            time += p;
            que.push({s,t-p});
        }
    }
}