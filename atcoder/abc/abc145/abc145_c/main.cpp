#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 8;
int X[MAX_N]; int Y[MAX_N];
bool used[MAX_N];
vector<double> ans; int N;

double dist(int i, int j) {
    return sqrt(pow(X[i]-X[j], 2)+pow(Y[i]-Y[j], 2));
}

void solve(int curr, double d, int k) {
    if (k==N) { ans.push_back(d); return; }
    used[curr] = true;
    for(int i=0; i<N; i++) if (!used[i]) solve(i, dist(curr, i)+d, k+1);
    used[curr] = false;
}

int main()
{
    cout << fixed << std::setprecision(20);
    cin >> N; rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) solve(i, 0.0, 1);
    double sum = 0;
    for(double s: ans) sum+=s;
    printf("%.10lf\n", sum/ans.size());
}