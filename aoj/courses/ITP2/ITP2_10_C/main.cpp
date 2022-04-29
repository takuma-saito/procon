#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ull;

int main()
{
    ull x=0;
    int Q; cin >> Q; while(Q--) {
        int op, i, j=0; cin >> op;
        switch (op)
        {
        case 0:
            cin >> i;
            printf("%d\n", x>>i&1);
            break;
        case 1:
            cin >> i;
            x |= (1ull<<i);
            break;
        case 2:
            cin >> i;
            x &= ~(1ull<<i);
            break;
        case 3:
            cin >> i;
            if(x>>i&1) x &= ~(1ull<<i);
            else x |= (1ull<<i);
            break;
        case 4:
            printf("%d\n", x==~0ull);
            break;
        case 5:
            printf("%d\n", x!=0ull);
            break;
        case 6:
            printf("%d\n", x==0ull);
            break;
        case 7:
            for(ull k=x; k>0; k>>=1ull) if(k&1) j++;
            printf("%d\n", j);
            break;
        case 8:
            printf("%llu\n", x);
            break;
        default:
            break;
        }
    }
}