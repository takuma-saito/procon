#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// TRY
const int MAX_N = 10;
map<char, int> ACGT = {{'A', 1}, {'C', 1}, {'G', 1}, {'T', 1}};

int main()
{
    string s; cin >> s;
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        int j=0; for(; i+j<s.size() && ACGT.count(s[i+j])>0; j++);
        ans = max(ans, j);
    }
    printf("%d\n", ans);
}