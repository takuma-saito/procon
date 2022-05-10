#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 時針： t = 2*PI*((h+m/60)/12), A*(sin(-t+PI/2), cos(-t+PI/2)) = A*(cos(t), sin(t))
// 分針： t = 2*PI*(m/60), B*(cos(t), sin(t))

int main()
{
    int A, B; double H, M; cin >> A >> B >> H >> M;
    double t1 = 2*M_PI*(H+(M/60))/12;
    double t2 = 2*M_PI*(M/60);
    printf("%.30lf", sqrt(pow(A*cos(t1)-B*cos(t2), 2)+pow(A*sin(t1)-B*sin(t2), 2)));
}