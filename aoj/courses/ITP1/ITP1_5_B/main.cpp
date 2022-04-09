#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        int H, W;
        cin >> H >> W;
        if(H==0||W==0) {break;}
        rep(i, W) {cout << "#";}
        cout << endl;
        rep(i, H-2) {
            rep(j, W) {
                cout << ((j==0||j==W-1) ? "#" : ".");
            }
            cout << endl;
        }
        rep(i, W) {cout << "#";}
        cout << endl << endl;;
    }
}