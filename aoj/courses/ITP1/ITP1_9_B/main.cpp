#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        queue<char> que;
        string s; cin >> s;
        if (s == "-") {break;}
        int m; cin >> m;
        for(char c: s) {que.push(c);}
        rep(i, m) {
            int h; cin >> h;
            rep(j ,h) {
                int x = que.front(); que.pop();
                que.push(x);
            }
        }
        while(!que.empty()) {
            cout << que.front(); que.pop();
        }
        cout << endl;
    }
}