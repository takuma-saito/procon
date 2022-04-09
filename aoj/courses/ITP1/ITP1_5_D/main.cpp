#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        if (i%3==0) {cout << " " << i << endl;}
        else {
            int x = i;
            while (x>0) {
                if (x%10==3) {cout << " " << i << endl; break;}
                x /= 10;
            }
        }
    }
}