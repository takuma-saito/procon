#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        int m, f, r; cin >> m >> f >> r;
        char score;
        if (m == -1 && f == -1 && r == -1) {break;}
        if (f == -1 || m == -1) {score='F';}
        else if (m+f>=80) {score='A';}
        else if (m+f>=65) {score='B';}
        else if (m+f>=50) {score='C';}
        else if (m+f>=30) {score=r>=50?'C':'D';}
        else {score='F';}
        cout << score << endl;
    }
}