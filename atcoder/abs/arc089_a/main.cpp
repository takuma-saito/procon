#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef struct Pos {
    int t;
    int x;
    int y;
    void Pos(int _t, int _x, int _y) {
        t = _t;
        x = _x;
        y = _y;
    }
} Pos;
vector<Pos> pos;

int main()
{
    int N;
    cin >> N;
    rep(i, N) {
        int t, x, y;
        cin >> t >> x >> y;
        pos.push_back(Pos(t, x, y));
    }
    sort(pos.begin(), pos.end(), [](Pos a, Pos b) {
        return a.t < b.t;
    });
}