#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Card {int l, r;};
const int MAX_N = 7;
int V;

int main()
{
    while (cin >> V) {
        int one[MAX_N] = {};
        int two[MAX_N] = {};
        int freq[MAX_N] = {};
        rep(i, V) {
            int c; cin >> c;
            int x=c/10, y=c%10;
            one[x]++;
            one[y]++;
            if (x==y) two[x]++;
        }
        int f=0; bool hasAloneDup=false;
        for(int i=0; i<MAX_N; i++) {
            if (one[i]&1) f++;
            if (one[i]>0 && two[i]*2==one[i]) hasAloneDup=true;
        }
        printf("%s\n", (V<2 || (!hasAloneDup && (f==0 || f==2))) ? "Yes" : "No");
    }
}