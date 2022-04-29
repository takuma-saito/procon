#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int N;

int main()
{
    cin >> N;
    for(int i=0; i<(1<<N); i++) {
        printf("%d:", i);
        for(int j=0; j<N; j++) if (i>>j&1) printf(" %d", j);
        printf("\n");
    }
}