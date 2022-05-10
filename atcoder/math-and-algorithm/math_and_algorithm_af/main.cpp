#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e3;
const double INF = 1e9;
struct Point {int x, y;};
int N; Point T[MAX_N];

double distance(Point& p1, Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    cin >> N; rep(i, N) { int x, y; cin >> x >> y; T[i] = Point {x, y}; }
    double ans = INF; for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
        ans = min(ans, distance(T[i], T[j]));
    }
    printf("%.30lf\n", ans);
}