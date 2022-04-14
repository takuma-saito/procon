#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 4;
const int NS = 16;
typedef int B[N][N];
struct State {
    int d;
    int t;
    B b;
    State() {
        this->d = 0;
        this->t = 0;
        rep(i, 4) rep(j, 4) this->b[i][j] = 0;
    }
    State(int d, int t, B b) {
        this->d = d;
        this->t = t;
        rep(i, 4) rep(j, 4) this->b[i][j] = b[i][j];
    }
    bool operator<(const State& rhs) const
    {
        if (d == rhs.d) return t < rhs.t;
        return d < rhs.d;
    }
    bool operator>(const State& rhs) const
    {
        if (d == rhs.d) return t > rhs.t;
        return d > rhs.d;
    }
};
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int dist(B& b) {
    int x[NS][2], y[NS][2];
    rep(i, NS) { x[i][0]=i/N; x[i][1]=i%N; }
    rep(i, N) rep(j, N) { int u = b[i][j]; y[u][0] = i; y[u][1] = j; }
    int sum = 0;
    rep(i, NS) sum += abs(x[i][0]-y[i][0]) + abs(x[i][1]-y[i][1]);
    return sum;
}

int main()
{
    State s; rep(i, N) rep(j, N) cin >> s.b[i][j];
    priority_queue<State, vector<State>, greater<State>> pq;
    s.d = dist(s.b);
    pq.push(s);
    while (!pq.empty()) {
        auto s = pq.top(); pq.pop();
        cout << s.d << " " << s.t << endl;
        if (s.d==0) {
            printf("%d\n", s.t);
            break;
        }
        int x = -1, y = -1;
        rep(i, N) rep(j, N) if(s.b[i][j]==0) {x=i; y=j;}
        if (x==-1||y==-1) runtime_error("wrong");
        for(auto [dx, dy]: d) {
            if (x+dx>=N || x+dx<0 || y+dy>=N || y+dy<0) continue;
            swap(s.b[x][y], s.b[x+dx][y+dy]);
            pq.push(State(dist(s.b), s.t+1, s.b));
            swap(s.b[x][y], s.b[x+dx][y+dy]);
        }
    }
}