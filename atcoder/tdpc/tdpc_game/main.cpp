#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1001;
int A[MAX_N]; int B[MAX_N];

// 相手の得点の最大値
int game(int a, int b, int me) {
    if (a==0 && b==0) return 0;
    int a1=0, b1=0;
    if (a-1>=0) a1 = game(a-1, b);
    if (b-1>=0) b1 = game(a, b-1);
    if (a1 < b1) {
        
    } else {

    }
    return res;
}

int main()
{
    
}