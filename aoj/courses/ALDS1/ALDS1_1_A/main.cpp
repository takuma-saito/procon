#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, size; cin >> n;
    vector<int> A;
    rep(i, n) {int x; cin >> x; A.push_back(x);}
    size = A.size();
    for (int i = 0; i<size; i++) {
        int j = i - 1;
        while (j>=0 && A[j]>A[j+1]) {swap(A[j], A[j+1]);j--;}
        rep(k, size) {
            cout << A[k] << (k==size-1?"":" ");
        }
        cout << endl;
    }
}