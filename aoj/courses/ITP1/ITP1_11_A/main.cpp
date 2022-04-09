#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
class Dice {
    // 1, 5, 3, 2, 4, 6
    int s[7]; // null, front, N, E, S, W, back
    public:
    Dice(int _s[7]) {
        int __s[7] = {-1, _s[1], _s[5], _s[3], _s[2], _s[4], _s[6]};
        rep(i, 7) { s[i] = __s[i]; }
        debug();
    }
    int front() {
        return s[1];
    }
    void north() {
        int _s[7] = {-1, s[2], s[1], s[3], s[6], s[4], s[5]};
        rep(i, 7) { s[i] = _s[i]; }
    }
    void east() {
        int _s[7] = {-1, s[4], s[5], s[1], s[2], s[6], s[3]};
        rep(i, 7) { s[i] = _s[i]; }
    }
    void south() {
        int _s[7] = {-1, s[5], s[6], s[3], s[1], s[4], s[2]};
        rep(i, 7) { s[i] = _s[i]; }
    }
    void west() {
        int _s[7] = {-1, s[3], s[5], s[6], s[2], s[1], s[4]};
        rep(i, 7) { s[i] = _s[i]; }
    }
    void debug() {
        rep(i, 7) { cout << s[i] << " ";}
        cout << endl;
    }
};

int main()
{
    int label[7];
    rep(i, 6) {cin >> label[i+1];}
    Dice dice(label);
    string s; cin >> s;
    for(char c: s) {
        cout << c;
        if (c=='N') {dice.north();}
        else if (c=='E') {dice.east();}
        else if (c=='S') {dice.south();}
        else if (c=='W') {dice.west();}
        cout << " " << dice.front() << endl;
        dice.debug();
    }
    cout << dice.front() << endl;
}
