#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, a, b;
    cin >> x >> a >> b;

    // 1.の出力
    x++;
    cout << x << endl;

    // ここにプログラムを追記
    x *= (a+b);
    cout << x << endl;
    x *= 2;
    cout << x << endl;
    x--;
    cout << x << endl;
}