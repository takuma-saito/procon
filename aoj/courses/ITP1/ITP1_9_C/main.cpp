#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n; cin >> n;
    int taro=0, hanako=0;
    rep(i, n) {
        string s1, s2; cin >> s1 >> s2;
        if(s1 > s2) {
            taro += 3;
        } else if (s1 < s2) {
            hanako += 3;
        } else {
            hanako++; taro++;
        }
    }
    cout << taro << " " << hanako << endl;
}