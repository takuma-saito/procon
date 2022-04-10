#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Pos { double x, y; };

Pos rotate60(Pos p) {
    return Pos {
        p.x*cos(M_PI/3.0) - p.y*sin(M_PI/3.0),
        p.x*sin(M_PI/3.0) + p.y*cos(M_PI/3.0),
    };
}

void koch(int n, Pos p1, Pos p2) {
    if (n==0) {
        printf("%3.8f %3.8f\n", p1.x, p1.y);
        return;
    }
    Pos s = {
        p1.x + (p2.x-p1.x)/3.0,
        p1.y + (p2.y-p1.y)/3.0,
    };
    Pos t = {
        p1.x + 2.0*(p2.x-p1.x)/3.0,
        p1.y + 2.0*(p2.y-p1.y)/3.0,
    };
    Pos r1 = rotate60(Pos {t.x-s.x, t.y-s.y});
    Pos u = {
        s.x+r1.x,
        s.y+r1.y,
    };
    koch(n-1, p1, s);
    koch(n-1, s, u);
    koch(n-1, u, t);
    koch(n-1, t, p2);
}

int main()
{
    int n; cin >> n;
    Pos p = Pos {100, 0};
    koch(n, Pos {0, 0}, p);
    printf("%3.8f %3.8f\n", p.x, p.y);
}