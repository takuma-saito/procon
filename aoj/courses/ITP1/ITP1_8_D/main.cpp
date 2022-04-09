#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s1, s2; cin >> s1 >> s2;
    int d1 = s1.size(), d2 = s2.size();
    rep(j, d1) {
        int i = 0;
        while(true) {
            if (i == d2) {
                cout << "Yes" << endl;
                return 0;
            } else if (s1[(j+i)%d1]==s2[i]) {
                i++;
            } else {break;}
        }
    }
    cout << "No" << endl;
}