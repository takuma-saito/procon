#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// TODO
struct Point {
    double x, y;
    double dot(Point other) {
        return x*other.x+y*other.y;
    }
    Point times(double d) {
        x *= d;
        y *= d;
        return *this;
    }
    Point operator -(Point other) {
        return Point {
            x - other.x,
            y - other.y,
        };
    }
    Point operator +(Point other) {
        return Point {
            x + other.x,
            y + other.y,
        };
    }
};

int main()
{
    Point a, b, c;
    for (auto p: {&a, &b, &c}) {
        double x, y; cin >> x >> y;
        p->x = x; p->y = y;
    }
    double t = (a.dot(b-c) - (b-c).dot(b-c))/(b.dot(c)-c.dot(c));
    Point d = b.times(t) + (c-b).times(1-t);
    printf("%.30lf\n", (d-a).dot(b-c));
    double ans = sqrt((a-d).dot(a-d));
    printf("%.30lf\n", ans);
}