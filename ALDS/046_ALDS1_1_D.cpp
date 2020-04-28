/**
 * Maximum Profit
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  // R = その時点の価格
  // min = 最低価格(十分に大きな値を初期値として与えておく)
  // profit = 利益(十分に小さな値を初期値として与えておく)
  // int R, min_price = numeric_limits<int>::max(), profit = numeric_limits<int>::min();
  int R, min_price = INT_MAX, profit = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> R;

    // 最大収益を更新する
    profit = max(profit, R - min_price);
    // 最低価格を更新する
    min_price = min(min_price, R);
  }

  cout << profit << endl;

  /**
  // R = その時点の価格
  // min = 最低価格
  // profit = 利益
  int R, min = -1, profit  = -200_000;

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
  */

}
