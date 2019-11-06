/**
 * Maximum Profit
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D&lang=ja
 */

#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  // R = その時点の価格
  // min = 最低価格
  // profit = 利益
  int R, min, profit;

  for (int i = 0; i < n; i++) {
    cin >> R;

    // 1回目は最低価格を更新するだけで良い
    if (i == 0) {
      min = R;
      continue;
    }

    // 2回目以降は利益計算を実施する
    if (i == 1 || R - min > profit) {
      profit = R - min;
    }

    // 最低価格を更新しているかどうか
    if (R < min) {
      min = R;
    }
  }

  cout << profit << endl;

  return 0;
}
