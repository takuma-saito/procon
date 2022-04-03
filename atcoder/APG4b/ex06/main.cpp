#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    string OP;
    cin >> A >> OP >> B;
    if (OP == "+") {
        C = A + B;
    } else if (OP == "-") {
        C = A - B;
    } else if (OP == "/") {
        C = A / B;
    } else if (OP == "*") {
        C = A * B;
    } else {
        // 発生し得ない
    }
    cout << C << endl;
}