#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Puddle { int area, height, l, r; };

int main()
{
    vector<Puddle> vec;
    string s; cin >> s;
    int height = 0, flat = 0, max_area = 0, max_height=0;
    for(int i=0; i<s.size(); i++) {
        char c=s[i];
        if (c != '_') {flat=0;}
        if (c == '/' && max_height == height) {
            height++;
        } else if (c == '/') {
            height++;
            int area=0, l=-1, r=0;
            while(!vec.empty()) {
                Puddle& pud = vec.back();
                if (pud.height >= height) break;
                if (l!=-1 && pud.r!=l) break;
                vec.pop_back();
                area += pud.area;
                if(l==-1) {l=pud.l;}
                r = pud.r;
            }
            vec.push_back(Puddle {area+(r-l)+1, height, l-1, r+1});
        } else if (c == '_') {
            vec.push_back(Puddle {0, height, i, i+1});
        } else if (c == '\\') {
            height--;
        } else {
            runtime_error("unknown char: "+c);
        }
        max_height = max(max_height, height);
        rep(i, vec.size()) {printf("%d %d %d %d\n", vec[i].area, vec[i].height, vec[i].l, vec[i].r);}
        printf("%c: %d\n", c, vec.size());
        cout << endl;
    }
    int sum = 0, number_of_puddle=0;
    rep(i, vec.size()) {sum+=vec[i].area; if(vec[i].area!=0) number_of_puddle++;}
    printf("%d\n", sum);
    printf("%d ", number_of_puddle);
    rep(i, vec.size()) {
        if (vec[i].area == 0) continue;
        cout << vec[i].area << (i==vec.size()-1?"\n":" ");
    }
}