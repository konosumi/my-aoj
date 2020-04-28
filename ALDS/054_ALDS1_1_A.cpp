/**
 * Insertion Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=ja
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
  trace(A);

  /**
   * insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
   *   for i が 1 から N-1 まで
   *     v = A[i]
   *     j = i - 1
   *     while j >= 0 かつ A[j] > v
   *       A[j+1] = A[j]
   *       j--
   *     A[j+1] = v
   */
  for (int i = 1; i < N; i++) {
    int v = A.at(i);
    int j = i - 1;
    while (j >= 0 && A.at(j) > v) {
      A.at(j + 1) = A.at(j);
      // cout << "途中経過 ";
      // trace(A);
      j--;
    }
    A.at(j + 1) = v;

    // 現在の並び替え状態を出力する
    trace(A);
  }

  return 0;
}
