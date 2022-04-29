#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> vec;
    int N; cin >> N;
    rep(i, N) vec.push_back(i+1);
    do {
        rep(i, N) printf("%d%s", vec[i], i==N-1?"\n":" ");
    } while(next_permutation(vec.begin(), vec.end()));
}