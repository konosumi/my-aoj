/**
 * Bubble Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

void trace(vector <int>A) {
  // 現在の並び替え状態を出力する
  int size = A.size();
  for (int i = 0; i < size; i++) {
    cout << A.at(i);
    if (i < size - 1) {
      cout << ' ';
    }
  }

  cout << endl;
}

int main() {
  int N;
  cin >> N;

  vector <int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  // trace(A);
  
  /**
   * bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
   *   flag = 1 // 逆の隣接要素が存在する
   *   while flag
   *     flag = 0
   *     for j が N-1 から 1 まで
   *       if A[j] < A[j-1]
   *         A[j] と A[j-1] を交換
   *         flag = 1
   */
  int count = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = N - 1; j > 0; j--) {
      if (A.at(j) < A.at(j - 1)) {
        swap(A.at(j), A.at(j - 1));
        count++;
        flag = true;
        // trace(A);
      }
    }
  }

  trace(A);
  cout << count << endl;
}
