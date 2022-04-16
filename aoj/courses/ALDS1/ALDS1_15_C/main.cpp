#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Act {int s, t;};

int main()
{
    vector<Act> acts;
    int n; cin >> n;
    rep(i, n) {int s, t; cin >> s >> t; acts.push_back(Act{s, t});}
    sort(acts.begin(), acts.end(), [](Act &a1, Act &a2) {return a1.t < a2.t;});
    int ans=0, prev_t=0;
    for(int i=0;i<n;) {
        int j=i;
        for(; j<n; j++) if (acts[j].s > prev_t) break;
        if (j==n) break;
        ans++;
        prev_t = acts[j].t;
        i=j+1;
    }
    printf("%d\n", ans);
}