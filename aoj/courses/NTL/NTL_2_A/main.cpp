#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100001;
int C[MAX_N];
string A, B;

// A+B, (A>B>=0)
void calc_plus(int k) {
    int a = A[k] - '0';
    int b = B[k] - '0';
    int g = a+b+C[k];
    int u = g/10, v = g%10;
    C[k] = v;
    if (u>0) C[k+1] += u;
}

// A-B, (A>B>=0)
void calc_minus(int k) {
    int a = A[k] - '0';
    int b = B[k] - '0';
    int g = a-b+C[k];
    if (g < 0) {}
}

int main()
{
    fill(C, C+MAX_N, 0);
    cin >> A >> B;
    if (A.size() < B.size()) swap(A, B);
    rep(i, B.size()) calc_plus(i);
    int bs = B.size(), as = A.size();
    rep(i, as-bs) C[bs+i] = A[bs+i] - '0';
    rep(i, as) printf("%d", C[i]);
    if (C[as] != 0) printf("%d", C[as]);
    cout << endl;
}