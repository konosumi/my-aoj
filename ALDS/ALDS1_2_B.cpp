/**
 * Selection Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=ja
 */

#include<iostream>
#include<vector>
using namespace std;

void trace(vector <int>A) {
  // 現在の並び替え状態を出力する
  int size = A.size();
  for (int i = 0; i < size; i++) {
    cout << A.at(i);
    if (i < size - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
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
   * selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
   *   for i が 0 から N-1 まで
   *   minj = i
   *   for j が i から N-1 まで
   *     if A[j] < A[minj]
   *       minj = j
   *       A[i] と A[minj] を交換
   */
   int count = 0;
   for (int i = 0; i < N; i++) {
     int minj = i;
     // 最小要素の位置を探索する
     for (int j = i; j < N; j++) {
       if (A.at(j) < A.at(minj)) {
         minj = j;
       }
     }

     // 最小要素を未ソート配列の先頭に移動する
     if (i != minj) {
       swap(A.at(i), A.at(minj));
       count++;
     }
   }

  trace(A);
  cout << count << endl;
}
