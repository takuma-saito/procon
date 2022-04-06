#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    int num = 0;
    rep(i, 3) {num += s[i] == '1' ? 1 : 0}
    cout << num << endl;
}