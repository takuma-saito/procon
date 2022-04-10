#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 考え方、{w, h, area} の 3 つをスタックで保存する
// "/" のとき =>
//       stack に要素があるとき => stack の先頭を見て、現在の高さより下の場合 pop して、面積を全部足す。
//       合計の width, (合計の面積area)+flat, 現在の高さ height を再度 stack に push して次へ
// "\" のとき => height--
// "_" のとき => flat++

struct Puddle { int area, height, width, flat; };

int main()
{
    vector<Puddle> vec;
    map<int, int> heights; // TODO
    string s; cin >> s;
    int height = 0, flat = 0, max_area = 0;
    for(int idx=0; idx<s.size(); idx++) {
        char c = s[i];
        if (c == '/') {
            height++;
            int area = 0, area_width=0, _flat=0;
            while(!vec.empty()) {
                Puddle& pud = vec.back();
                if (pud.height >= height) {break;}
                vec.pop_back();
                area += pud.area;
                area_width += pud.width;
                flat += pud.flat;
            }
            cout << area+area_width+flat+1 << " " << area << " " << area_width << " " << flat << endl;
            while(s[idx++] == '_') {_flat++;} // TODO
            idx--;
            vec.push_back(Puddle {area+area_width+flat+1, height, area_width+flat+2, _flat});
            flat = 0;
        } else if (c == '_') {
            heights[flat]++; // TODO
        } else if (c == '\\') {
            height--;
        } else {
            runtime_error("unknown char: "+c);
        }
    done:
        rep(i, vec.size()) {printf("%d %d %d %d\n", vec[i].area, vec[i].height, vec[i].width, vec[i].flat);}
        printf("%c: %d\n", c, vec.size());
        cout << endl;
    }
    int sum = 0;
    rep(i, vec.size()) {sum+=vec[i].area;}
    printf("%d\n", sum);
    rep(i, vec.size()) {cout << vec[i].area << (i==vec.size()-1?"\n":" ");}
}