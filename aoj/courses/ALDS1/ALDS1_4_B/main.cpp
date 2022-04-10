#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int T[50000];

int main()
{
    int n, ans=0; cin >> n;
    vector<int> S;
    rep(i, n) {int x; cin >> x; S.push_back(x);}
    sort(S.begin(), S.end());
    int q; cin >> q;
    rep(i, q) {
        int x; cin >> x;
        int lb=0, ub=S.size();
        while (ub-lb>1) {
            int mid = (ub+lb)/2;
            if (S[mid] == x) {lb = mid; break;}
            else if (S[mid] > x) {ub=mid;}
            else {lb=mid;}
        }
        if(S[lb]==x) {ans++;}
    }
    printf("%d\n", ans);
}