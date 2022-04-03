#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<int, int> xs;
    int N;
    cin >> N;
    rep(i, N) {
        int x;
        cin >> x;
        xs[x] += 1;
    }
    int mode = -1;
    int mode_idx = -1;
    for (auto x : xs) {
        if (mode < x.second) {
            mode = x.second;
            mode_idx = x.first;

        }
    }
    cout << mode_idx << " " << mode << endl;
}