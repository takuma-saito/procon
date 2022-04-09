#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int x, y; cin >> x >> y;
    if (x<y) {swap(x, y);} // y>=x
    while(x != 0) {
        int tmp = x;
        x = y % x;
        y = tmp;
    }
    cout << y << endl;
}