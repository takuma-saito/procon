#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    cout << fixed << std::setprecision(20);
    while (true) {
        int sum = 0;
        vector<int> vec;
        int n; cin >> n;
        if (n==0) {break;}
        rep(i, n) {int x; cin >> x; vec.push_back(x); sum+=x;}
        double avg = double(sum)/n, sigma=0;
        for(int x: vec) {sigma += pow((x-avg), 2);}
        cout << sqrt(sigma/n) << endl;
    }
}