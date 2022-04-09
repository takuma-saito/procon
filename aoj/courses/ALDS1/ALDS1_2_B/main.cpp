#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, ans=0; cin >> n;
    vector<int> vec; rep(i, n) {int x; cin >> x; vec.push_back(x);}
    for(int i=0; i<n; i++) {
        int m = vec[i];
        int k = i;
        for(int j=i; j<n; j++)  {if (m>vec[j]) {m=vec[j];k=j;}}
        if(k!=i) {swap(vec[i], vec[k]);ans++;}
    }
    rep(i, n) {cout << vec[i] << (i==n-1?"":" ");}
    cout << endl << ans << endl;
}