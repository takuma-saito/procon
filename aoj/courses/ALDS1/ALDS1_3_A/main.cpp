#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

pair<int, int> pop(vector<int> &vec) {
    int a = vec.back(); vec.pop_back();
    int b = vec.back(); vec.pop_back();
    return {a, b};
}

int main()
{
    vector<int> vec;
    int ans = 0;
    while(true) {
        string s;
        cin >> s;
        if (cin.eof()) {break;}
        if (s == "+") {
            auto [a,b] = pop(vec);
            vec.push_back(b+a);
        } else if (s == "-") {
            auto [a,b] = pop(vec);
            vec.push_back(b-a);
        } else if (s == "*") {
            auto [a,b] = pop(vec);
            vec.push_back(b*a);
        } else {
            vec.push_back(stoi(s));
        }
    }
    cout << vec.front() << endl;
}