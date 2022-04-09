#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    list<int> items;
    int n; cin >> n;
    rep(i, n) {
        string op; int x; cin >> op;
        if (op == "insert") {
            cin >> x;
            items.push_front(x);
        } else if (op == "delete") {
            cin >> x;
            for(auto it = items.begin(); it != items.end();) {
                if (*it == x) {
                    it = items.erase(it);
                    break;
                } else {it++;}
            }
        } else if (op == "deleteLast") {
            items.pop_back();
        } else if (op == "deleteFirst") {
            items.pop_front();
        } else {
            runtime_error("unknown op "+op);
        }
    }
    while(!items.empty()) {
        int item = items.front(); items.pop_front();
        cout << item << (items.size()==0?"":" ");
    }
    cout << endl;
}