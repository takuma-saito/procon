#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Card {int l, r;};
const int MAX_N = 30;
int V; bool used[MAX_N]; vector<Card> cards;

int dfs(int v, int num, bool l) {
    used[v] = true;
    auto &card = cards[v];
    int x = l ? card.l : card.r;
    if (++num==V) return true;
    rep(u, cards.size()) {
        auto &card_next = cards[u];
        if (!used[u] && (card_next.l == x || card_next.r == x)) {
            if (dfs(u, num, card_next.l != x)) return true;
        }
    }
    used[v] = false;
    return false;
}

int main()
{
    while (cin >> V) {
        cards.clear();
        rep(i, V) {
            string c; cin >> c;
            cards.push_back({c[0]-'0', c[1]-'0'});
        }
        bool ans = false;
        rep(u, V) {
            fill(used, used+MAX_N, false);
            ans |= dfs(u, 0, true);
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
}