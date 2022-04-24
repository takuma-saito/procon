#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
    int M; cin >> M;
    vector<P> vec;
    rep(i, M) {int x, y; cin >> x >> y; vec.push_back(P{x, y});}
    int N; cin >> N;
    map<P, bool> stars;
    rep(i, N) {int x, y; cin >> x >> y; stars[P{x, y}] = true;}

    auto [x, y] = vec[0];
    for(auto [p, _]: stars) {
        bool ans = true;
        int dx=p.first-x, dy=p.second-y;
        rep(j, M) {
            auto [nx, ny] = vec[j];
            if (stars.count({nx+dx, ny+dy})==0) {
                ans = false;
                break;
            }
        }
        if (ans) {
            printf("%d %d\n", dx, dy);
            return 0;
        }
    }
}