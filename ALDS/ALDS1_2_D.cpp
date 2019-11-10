/**
 * Shell Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D&lang=ja
 */

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int cnt = 0;

/**
 * 現在の並び替え状態を出力する
 */
void trace(vector <int>A) {
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

vector <int>insertionSort(vector <int>A, int N, int g) {
  /**
   * insertionSort(A, n, g)
   *   for i = g to n-1
   *     v = A[i]
   *     j = i - g
   *     while j >= 0 && A[j] > v
   *       A[j+g] = A[j]
   *       j = j - g
   *       cnt++
   *     A[j+g] = v
   */
  for (int i = g; i < N; i++) {
    int v = A.at(i);
    int j = i - g;
    while (j >= 0 && A.at(j) > v) {
      A.at(j + g) = A.at(j);
      // cout << "途中経過 ";
      // trace(A);
      j = j - g;
      cnt++;
    }
    A.at(j + g) = v;
  }

  return A;
}

vector <int>shellSort(vector <int>A, int N) {
  /**
   * shellSort(A, n)
   *   cnt = 0
   *   m = ?
   *   G[] = {?, ?,..., ?}
   *   for i = 0 to m-1
   *     insertionSort(A, n, G[i])
   */
  vector <int>G;

  // 3倍した値に1を加える
  for (int h = 1; h < N; h = 3 * h + 1) {
      G.push_back(h); 
  }

  // Nが1でも、1回はソートすること
  if (G.size() == 0) {
    G.push_back(1);
  }

  std::reverse(G.begin(), G.end());

  // 選択ソートを実行する
  int m = G.size();
  for (int i = 0; i < m; i++) {
    A = insertionSort(A, N, G.at(i));
  }
  
  // 結果の出力
  cout << m << endl;
  trace(G);
  cout << cnt << endl;
  int size = A.size();
  for (int i = 0; i < size; i++) {
    cout << A.at(i) << endl;
  }
 
  return A;
}


int main() {
  int N;
  cin >> N;

  vector <int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  //trace(A);

  vector <int>B = shellSort(A, N);
  //trace(B);

  return 0;
}

