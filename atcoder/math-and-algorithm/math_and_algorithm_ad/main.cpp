#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    set<int> st; int N, X; cin >> N >> X; rep(i, N) { int x; cin >> x; st.insert(x); }
    printf("%s\n", st.count(X)>0?"Yes":"No");
}