#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    priority_queue<int> pq;
    for(;;) {
        string op; cin >> op;
        if (op == "extract") { printf("%d\n", pq.top()); pq.pop(); }
        else if (op == "insert") { int x; cin >> x; pq.push(x); }
        else if (op == "end") break;
        else runtime_error("unknwon op+"+op);
    }
}
