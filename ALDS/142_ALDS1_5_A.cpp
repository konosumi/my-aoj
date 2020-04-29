/**
 * Exhaustive Search
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
 */

#include<iostream>
#include<vector>
using namespace std;

// 長さ n の数列 A 
int n;
vector <int>A(20); // n≤20

bool solve(int total, int index, int m) {
  // 合計が等しい。つまりmを作れる
  if (total == m) {
    return true;
  }
  // 長さを超えてしまった時点で、mを作ることはできない
  if (index >= n) {
    return false;
  }

  // A[index]を選んで加算するケースと、選ばず加算されないケースの両方を試行し、次の要素へ進める
  return solve(total, index + 1, m) || solve(total + A.at(index), index + 1, m);
}

int main() {
  // 長さ n の数列 A 
  // int n;
  cin >> n;
  // vector <int>A(n);
  for (int i = 0; i < n; i++) {
    cin >> A.at(i);
  }

  // 質問として q 個の mi が与えれる
  int q;
  cin >> q;
  // vector <int>m(n);
  for (int i = 0; i < q; i++) {
    // 足し合わせて作りたいm
    int m;
    cin >> m;

    // 0番目の要素から判定をスタートし、mを作れるかどうか
    if (solve(0, 0, m)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
