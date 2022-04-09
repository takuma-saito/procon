#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
char C[4] = {'S', 'H', 'C', 'D'};

int main()
{
    int n;
    map<pair<char, int>, bool> cards;
    cin >> n;
    rep(i, n) {
        int j; char c;
        cin >> c >> j;
        cards.insert({{c, j}, true});
    }
    for(char c : C) {
        for(int j = 1; j<=13; j++) {
            if (cards.find({c, j}) != cards.end()) {continue;}
            cout << c << " " << j << endl;
        }
    }
}