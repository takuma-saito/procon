#include <bits/stdc++.h>
#include <boost/format.hpp>
using namespace std;

struct Clock {
    int hour;
    int minute;
    int second;
    void set(int _hour, int _minute, int _second) {
        hour   = _hour;
        minute = _minute;
        second = _second;
    }
    string to_str() {
        return (boost::format("%02d:%02d:%02d") % hour % minute % second).str();
    }
    void shift(int _second) {
        second += _second + 86400;
        minute += second/60;
        hour   += minute/60;
        second = (second%60+60)%60;
        minute = (minute%60+60)%60;
        hour   = (hour%24+24)%24;
    }
};


// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // 入力を受け取る
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock構造体のオブジェクトを宣言
  Clock clock;

  // set関数を呼び出して時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
}
