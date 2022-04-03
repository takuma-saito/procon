#include <bits/stdc++.h>
using namespace std;

int main()
{
    int price, N, op;
    string text;
    cin >> op;
    if (op == 2) {
        cin >> text;
        cout << "!" + text << endl;
    } else if (op != 1) {
        runtime_error("op is invalid: " + op);
    }
    cin >> price;
    cin >> N;
    cout << N*price << endl;
}