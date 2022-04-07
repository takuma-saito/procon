#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef struct Pos {
    int t;
    int x;
    int y;
} Pos;
vector<Pos> pos;

int main()
{
    int N;
    cin >> N;
    pos.push_back(Pos {0, 0, 0});
    rep(i, N) {
        int t, x, y;
        cin >> t >> x >> y;
        pos.push_back(Pos {t, x, y});
    }
    sort(pos.begin(), pos.end(), [](Pos a, Pos b) {
        return a.t < b.t;
    });
    for(int i=1; i<=N; i++) {
        int v = abs(pos[i].x - pos[i-1].x) + abs(pos[i].y - pos[i-1].y);
        int t = pos[i].t-pos[i-1].t;
        if (t-v<0 || (t-v)&1) {cout << "No" << endl; return 0;}
    }
    cout << "Yes" << endl;
}