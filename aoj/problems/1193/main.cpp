#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_H = 10;
const int MAX_W = 5;
int H, W=MAX_W; vector<vector<int>> T;

int ball_check() {
    int sum=0;
    rep(h, H) rep(w, W) {
        int d = T[h][w]; int cnt=1;
        if (!d) continue;
        for (int k=w+1; k<W; k++) {
            if (d==T[h][k]) cnt++;
            else break;
        }
        if (cnt>=3) {
            sum += cnt*d;
            while (cnt--) { T[h][w+cnt] = 0; }
            break;
        }
    }
    return sum;
}

void ball_delete() {
    for(int h=H-1; h>=0; h--) {
        rep(w, W) {
            for(int k=h; k+1<H; k++) {
                if (T[k][w] && !T[k+1][w]) {
                    swap(T[k][w], T[k+1][w]);
                }
            }
        }
    }
}

int main()
{
    for(;;) {
        T.clear();
        cin >> H;
        if (!H) break;
        rep(h, H) {
            vector<int> vec;
            rep(w, W) {
                int x; cin >> x; vec.push_back(x);
            }
            T.push_back(vec);
        }
        int sum=0; for(;;) {
            int ball = ball_check();
            if (!ball) break;
            sum += ball;
            ball_delete();
        }
        printf("%d\n", sum);
    }
}