#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 3;
const int NS = 9;
typedef int B[N][N];
int G[NS][2];
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
    uint64_t hash() {
        uint64_t res = 0;
        rep(i, N) rep(j, N) res += res * 107 + b[i][j];
        return res;
    }
    void dump() {
        rep(i, N) rep(j, N) printf("%d%s", b[i][j], j==N-1?"\n":" ");
    }
    bool operator<(const State& rhs) const
    {
        if (t == rhs.t) return d < rhs.d;
        return t < rhs.t;
    }
    bool operator>(const State& rhs) const
    {
        if (t == rhs.t) return d > rhs.d;
        return t > rhs.t;
    }
    bool operator==(const State& rhs) const
    {
        bool res=true;
        rep(i, N) rep(j, N) res = (res && (b[i][j] == rhs.b[i][j]));
        return res;
    }
};
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int dist(B& b) {
    int y[NS][2];
    rep(i, N) rep(j, N) { int u = b[i][j]; y[u][0] = i; y[u][1] = j; }
    int sum = 0;
    rep(i, NS) sum += abs(G[i][0]-y[i][0]) + abs(G[i][1]-y[i][1]);
    return sum;
}

int calc(int x, int y, int n) {
    int u = x*4+y;
    return abs(G[u][0]-n/N)+abs(G[u][1]-(n%N));
}

int main()
{
    map<uint64_t, bool> used;
    State s; rep(i, N) rep(j, N) cin >> s.b[i][j];
    priority_queue<State, vector<State>, greater<State>> pq;
    rep(i, NS-1) { G[i+1][0]=i/N; G[i+1][1]=i%N; }
    G[0][0]=N-1; G[0][1]=N-1;
    s.d = dist(s.b);
    pq.push(s);
    while (!pq.empty()) {
        auto s = pq.top(); pq.pop();
        if (s.d==0) {
            printf("%d\n", s.t);
            break;
        }
        // s.dump();
        // cout << s.d << " " << s.t << endl;
        // cout << endl;
        if (used[s.hash()]) continue;
        used[s.hash()] = true;
        int x = -1, y = -1;
        rep(i, N) rep(j, N) if(s.b[i][j]==0) {x=i; y=j;}
        if (x==-1||y==-1) runtime_error("wrong");
        for(auto [dx, dy]: d) {
            if (x+dx>=N || x+dx<0 || y+dy>=N || y+dy<0) continue;
            //printf("(%d, %d) => (%d, %d)\n", x, y, x+dx, y+dy);
            swap(s.b[x][y], s.b[x+dx][y+dy]);
            pq.push(State(dist(s.b), s.t+1, s.b));
            swap(s.b[x][y], s.b[x+dx][y+dy]);
        }
    }
}