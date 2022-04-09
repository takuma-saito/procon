#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void check_stable(int n, vector<string> &orig_vec, vector<string> &vec) {
    rep(i, n) {
        rep(j, n) {
            if (orig_vec[i][1] == orig_vec[j][1]) {
                int si = distance(vec.begin(), find(vec.begin(), vec.end(), orig_vec[i]));
                int sj = distance(vec.begin(), find(vec.begin(), vec.end(), orig_vec[j]));
                if (i < j && si > sj) {cout << "Not stable" << endl; return;}
            }
        }
    }
    cout << "Stable"  << endl;
}

int main()
{
    int n; cin >> n;
    vector<string> vec; rep(i, n) {string s; cin >> s; vec.push_back(s);}
    vector<string> orig_vec = vec;
    for(int i=0; i<n; i++) {
        for(int j=n-1; j>i; j--) {
            if (vec[j][1] < vec[j-1][1]) {
                swap(vec[j], vec[j-1]);
            }
        }
    }
    rep(i, n) {cout << vec[i] << (i==n-1?"":" ");}
    cout << endl;
    check_stable(n, vec, orig_vec);
    vec = orig_vec;
    for(int i=0; i<n; i++) {
        int minj=i;
        for(int j=i; j<n; j++) {
            if (vec[j][1] < vec[minj][1]) {minj=j;}
        }
        swap(vec[minj], vec[i]);
    }
    rep(i, n) {cout << vec[i] << (i==n-1?"":" ");}
    cout << endl;
    check_stable(n, vec, orig_vec);
}