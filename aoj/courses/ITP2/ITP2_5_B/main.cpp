#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
struct Item {int value; int weight; char cat; ll date; string name;};
const int MAX_N = 1e5;
int N; Item A[MAX_N];

int main()
{
    cin >> N; rep(i, N) {
        int value; int weight; char cat; ll date; string name;
        cin >> value >> weight >> cat >> date >> name;
        A[i] = Item {value, weight, cat, date, name};
    }
    sort(A, A+N, [](const Item &a, const Item &b) {
        if (a.value != b.value) return a.value < b.value;
        if (a.weight != b.weight) return a.weight < b.weight;
        if (a.cat != b.cat) return a.cat < b.cat;
        if (a.date != b.date) return a.date < b.date;
        return a.name < b.name;
    });
    rep(i, N) printf("%d %d %c %lld %s\n", A[i].value, A[i].weight, A[i].cat, A[i].date, A[i].name.c_str());
}