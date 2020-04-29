/**
 * 線形探索
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A&lang=ja
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

  // 線形探索
  int cnt = 0;
  // Tに含まれる整数で、Sに含まれているものの個数をカウントする
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) {
      if (T.at(i) == S.at(j)) {
        cnt++;
        break;
      }
    }
  }
  
  cout << cnt << endl;
  return 0;
}
