#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int A[3];
    rep(i, 3) {cin >> A[i];}
    if (A[0] > A[1]) {swap(A[0], A[1]);}
    if (A[0] > A[2]) {swap(A[0], A[2]);}
    if (A[1] > A[2]) {swap(A[1], A[2]);}
    cout << A[0] << " " << A[1] << " " << A[2] << endl;
}