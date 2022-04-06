#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 100
vector<int> a;

int main()
{
    int N, alice = 0, total = 0;
    cin >> N;
    rep(i, N) {
        int x;
        cin >> x;
        total += x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    rep(i, a.size()) {
        if (i&1) {alice += a[i];}
    }
    cout << abs(total - 2*alice) << endl;
}