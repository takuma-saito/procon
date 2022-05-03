#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
    ll N; cin >> N;
    if (!(N&1)) goto no;
    for(ll i=3; i*i<=N; i += 2) {
        if (!(N%i)) goto no;
    }
    printf("Yes\n");
    return 0;
no:
    printf("No\n");
}