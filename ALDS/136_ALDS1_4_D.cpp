/**
 * Allocation
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D
 */

#include<iostream>
#include<vector>
using namespace std;

bool canPackToTrack(vector <int>w, int k, int P) {
  int capacity = 0;

  for (int i = 0; i < w.size(); i++) {
    // 最大積載量より大きい荷物は、そもそも積めない
    if (w.at(i) > P) {
      return false;
    }

    // 積載量を超えたら、トラックの数を減らして積載量をリセットする
    if (capacity + w.at(i) > P) {
      k--;
      capacity = 0;
    }

    // トラックがなくなってしまったら、もう荷物を積めない
    if (k == 0) {
      return false;
    }

    // トラックに荷物を積む
    capacity += w.at(i);
  }

  return true;
}

int main() {
  // 最初の行に荷物の数 n とトラックの数 k が空白区切りで与えられます。
  int n, k;
  cin >> n >> k;

  // 重さがそれぞれwのn個の荷物
  vector <int>w(n);
  for (int i = 0; i < n; i++) {
    cin >> w.at(i);
  }

  /**
   * 線形探索では、制限時間が足りなかった
   * for (int i = 0; 1; i++) {
   *   // cout << "=-" << i << calcV(w, k, i) << endl;
   *   if (calcV(w, k, i) >= n) {
   *     cout << i << endl;
   *     return 0;
   *   }
   * }
   */

   // 2分探索
   // 荷物の最大個数は100,000個で、最大サイズは10,000。これを超える十分に大きい最大積載量Pを最小値とする
   int min = 1, max = 100000 * 10000;
   int answer = 100000 * 10000;
   while (min < max) {
     int center = (min + max) / 2;
     if (canPackToTrack(w, k, center)) {
       // centerより大きい積載量の値は、必ず積載可能なので計算する必要がない
       max = center;
       if (center < answer) {
         answer = center;
       }
     } else {
       // centerより小さいサイズで、積載可能になることは起こり得ない
       min = center + 1;
     }
   }

   cout << answer << endl;
}
