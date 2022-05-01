#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct card {int left, right;};
const int MAX_N = 30;
int V; int G[MAX_N][MAX_N]; bool used[MAX_N];

bool dfs(int v, int num) {
    used[v] = true; num++;
    if (num==V)  return true;
    for(int u: G[v]) if (!used[u] && dfs(u, num+1)) return true;
    return false;
}

int main()
{
    while (cin >> V) {
        fill(used, used+MAX_N, false);
        vector<string> cards;
        rep(i, V) {
            string card; cin >> card;
            int S = cards.size();
            rep(j, S) {
                for(int x: {0, 1}) {
                    for(int y: {0, 1}) {
                        if (cards[j][x] == card[y]) {
                            G[j][S] = 1; G[S][j] = 1;
                        }
                    }
                }
            }
            cards.push_back(card);
        }
        rep(i, V) rep(j, V) printf("%d%s", G[i][j], j==V-1?"\n":" ");
        bool ans=false; rep(u, V) ans |= dfs(u, 0);
        printf("%s\n", ans ? "Yes" : "No");
    }
}