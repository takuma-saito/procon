#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e5;
int A[MAX_N]; int B[MAX_N];

int main()
{
    set<int> st;
    rep(i, 2) {
        int n; cin >> n; rep(i, n) {
            int x; cin >> x; st.insert(x);
        }
    }
    for(int d: st) printf("%d\n", d);
}