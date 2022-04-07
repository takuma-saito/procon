#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        int x, y;
        cin >> x >> y;
        if (x==0&&y==0) {break;}
        cout << min(x, y) << " " << max(x, y) << endl;
    }
}