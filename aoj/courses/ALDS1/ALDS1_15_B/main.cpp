#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Item {double v; int w;};
int N, W;
vector<Item> items;

int main()
{
    cout << fixed << std::setprecision(20);
    cin >> N >> W;
    rep(i, N) {int v, w; cin >> v >> w; items.push_back(Item {double(v)/w, w});};
    sort(items.begin(), items.end(), [](Item &a, Item &b){return a.v > b.v;});
    double ans=0, w=0;
    int i=0;
    for(;i<N; i++) {
        if (w+items[i].w>W) break;
        ans += items[i].v*items[i].w;
        w += items[i].w;
    }
    if (W-w>0 && i!=N) {
        ans += items[i].v*(W-w);
    }
    printf("%lf\n", ans);
}