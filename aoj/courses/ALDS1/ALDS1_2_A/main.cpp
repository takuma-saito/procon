#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, ans=0; cin >> n;
    vector<int> vec; rep(i, n) {int x; cin >> x; vec.push_back(x);}
    bool flag = true;
    while (flag) {
        flag = false;
        for(int i=n-1; i>0; i--) {
            if (vec[i-1] > vec[i]) {
                swap(vec[i], vec[i-1]);
                ans++;
                flag=true;
            }
        }
    }
    rep(i, n) {cout << vec[i] << (i==n-1?"":" ");}
    cout << endl << ans << endl;
}