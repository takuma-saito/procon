#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<string, int> dict;
    int n; cin >> n;
    rep(i, n) {
        string op, name; cin >> op >> name;
        if (op == "insert") {dict[name]++;}
        else if (op == "find") {printf("%s\n", dict[name]>0?"yes":"no");}
        else {
            runtime_error("unknwon op"+op);
        }
    }
}