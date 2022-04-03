#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 100
typedef pair<int, int> PINT;
vector<PINT> X;

int main()
{
    int N;
    cin >> N;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        X.push_back(pair(a,b));
    }
    sort(X.begin(), X.end(), [](PINT x, PINT y) {
        return x.second > y.second;
    });
    rep(i, N) {
        cout << X[i].first << " " << X[i].second << endl;
    }
}