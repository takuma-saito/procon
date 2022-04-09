#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 10001
bool prime_tables[MAX_N];

int main()
{
    vector<int> primes;
    fill(prime_tables, prime_tables+MAX_N, true);
    for(int i=2; i<MAX_N; i++) {
        if (!prime_tables[i]) {continue;}
        for(int j=i*2; j<=MAX_N; j+=i) {
            prime_tables[j] = false;
        }
    }
    for(int i=2; i<MAX_N; i++) {
        if(prime_tables[i]) {
            primes.push_back(i);
        } 
    }
    int ans = 0, n; cin >> n;
    rep(i, n) {
        bool divisible = false;
        int x; cin >> x;
        for (int p: primes) {
            if (x!=p&&x%p==0) {divisible=true;break;}
            else if (x<p*p) {break;}
        }
        if(!divisible) {ans++;}
    }
    cout << ans << endl;
}