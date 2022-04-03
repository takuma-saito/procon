#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int A[1000];

int main()
{
    int N;
    int sum = 0;
    cin >> N;
    rep(i, N) { cin >> A[i]; sum +=  A[i]; }
    rep(i, N) {
        cout << abs(A[i]-sum/N) << endl;
    }
}