#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 4;
const int NS = 16;
typedef int B[N][N];
int x[NS][2];
struct State {
    int d;
    int t;
    B b;
    State() {
        this->d = 0;
        this->t = 0;
        rep(i, N) rep(j, N) this->b[i][j] = 0;
    }
    State(int d, int t, B b) {
        this->d = d;
        this->t = t;
        rep(i, N) rep(j, N) this->b[i][j] = b[i][j];
    }
    void dump() {
        rep(i, N) rep(j, N) printf("%d%s", b[i][j], j==N-1?"\n":" ");
    }
    bool operator<(const State& rhs) const
    {
        if (d == rhs.d) t < rhs.t;
        return d < rhs.d;
    }
    bool operator>(const State& rhs) const
    {
        if (d == rhs.d) t > rhs.t;
        return d > rhs.d;
    }
    bool operator==(const State& rhs) const
    {
        bool res=true;
        rep(i, N) rep(j, N) res = res && (b[i][j] == rhs.b[i][j]);
        return res;
    }
};
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int dist(B& b) {
    int y[NS][2];
    rep(i, N) rep(j, N) { int u = b[i][j]; y[u][0] = i; y[u][1] = j; }
    int sum = 0;
    rep(i, NS) sum += abs(x[i][0]-y[i][0]) + abs(x[i][1]-y[i][1]);
    return sum;
}

int main()
{
    map<State, bool> used;
    State s; rep(i, N) rep(j, N) cin >> s.b[i][j];
    priority_queue<State, vector<State>, greater<State>> pq;
    rep(i, NS-1) { x[i+1][0]=i/N; x[i+1][1]=i%N; }
    x[0][0]=N-1; x[0][1]=N-1;
    s.d = dist(s.b);
    pq.push(s);
    while (!pq.empty()) {
        auto s = pq.top(); pq.pop();
        if (s.d==0) {
            printf("%d\n", s.t);
            break;
        }
        s.dump();
        cout << s.d << " " << s.t << endl;
        cout << endl;
        //if (used.count(s)) continue;
        //used[s] = true;
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