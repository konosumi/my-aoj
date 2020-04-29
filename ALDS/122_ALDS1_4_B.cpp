/**
 * 二分探索
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int>S(n);
  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
  }

  int q;
  cin >> q;
  vector <int>T(q);
  for (int i = 0; i < q; i++) {
    cin >> T.at(i);
  }

  // 二分探索
  int cnt = 0;
  // Tに含まれる整数で、Sに含まれているものの個数をカウントする
  for (int i = 0; i < q; i++) {
    int minJ = 0;
    int maxJ = n;
    // minJとmaxJが反転してしまったら、探索をしたが見つからなかったということになる
    while (minJ <= maxJ) {
      // Sの中央の値で比較することで、配列の前半と後半のどちらに求める値があるのかを探索する
      int j = (minJ + maxJ) / 2;

      if (S.at(j) < T.at(i)) {
        // 前半に探索する値は存在しない
        minJ = j + 1;
      } else if (S.at(j) > T.at(i)) {
        // 後半に探索する値は存在しない
        maxJ = j - 1;
      } else {
        // 要素が一致した
        cnt++;
        break;
      }
    }
  }
  
  cout << cnt << endl;
  return 0;
}
