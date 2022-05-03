#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    vector<int> primes;
    for (int i=2; i<=N; i++) {
        bool is_prime=true;
        for (int j=2; j*j<=i; j++) {
            if (!(i%j)) { is_prime=false; break; }
        }
        if (is_prime) primes.push_back(i);
    }
    rep(i, primes.size()) printf("%d%s", primes[i], i==primes.size()-1?"\n":" ");
}