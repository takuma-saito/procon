#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 100
vector<int> d;

int main()
{
    int N, ans = 1;
    cin >> N;
    rep(i, N) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    sort(d.begin(), d.end());
    for(int i = 1; i < d.size(); i++) {
        if (d[i] != d[i-1]) {ans++;}
    }
    cout << ans << endl;
}