#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
double P;

// d 年経過してから、コンピューターを切り替えるとする。切り替えたコンピューターで計算が終わるまで g 年かかるとする。
// 必要な計算リソースを L(d) とすると、以下が成り立つ
// L(d) = g*2^(d/1.5)
// 計算が完了する時間 d, p をそれぞれ、d1, p1 とすると、 L(d1) = P 成り立つため
// P = d1 + g1 * 2^(d1/1.5) の等式が成立する。これを g について解いて
// g1 = P*2^(-d1/1.5)
// 経過する時間は、 d1 + g1 = d1 + (P-d1)*2^(-d1/1.5) となる。変数 d1 を改めて d として、これを G(d) とすると
// G(d) = d+P*2^(-d/1.5) が d 時間後にコンピューターを切り替えた場合に最後まで完了するトータル時間となる。
// G(d) = d+P*exp(-log(2)*d/1.5)
// G'(d) = 1 - (P*log(2)/1.5)*2^(-d/1.5)
// G'(d) = 0 の時 d/1.5 * log(2) = log(P) + log(log(2)/1.5) => d = {log(P) + log(log(2)/1.5)}*(1.5/log(2))

double solve() {
    return (log(P) + log(log(2)/1.5))*(1.5/log(2));
}

double G(double d) {
    return d+P*pow(2, -d/1.5);
}

int main()
{
    cin >> P; 
    double d = solve();
    printf("%.10f\n", G(d<0?0:d));
}