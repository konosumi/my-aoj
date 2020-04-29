/**
 * Merge Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

/*
merge(A, left, mid, right)
  n1 = mid - left;
  n2 = right - mid;
  L[0...n1], R[0...n2] を生成
  for i = 0 to n1-1
    L[i] = A[left + i]
  for i = 0 to n2-1
    R[i] = A[mid + i]
  L[n1] = INFTY
  R[n2] = INFTY
  i = 0
  j = 0
  for k = left to right-1
    if L[i] <= R[j]
      A[k] = L[i]
      i = i + 1
    else 
      A[k] = R[j]
      j = j + 1

mergeSort(A, left, right)
  if left+1 < right
    mid = (left + right)/2;
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)
*/

int compareCount = 0;

void merge(vector<int> &A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  // L[0...n1], R[0...n2] を生成
  vector <int>L(n1 + 1);
  for (int i = 0; i < n1; i++) {
    L.at(i) = A.at(left + i);
  }
  vector <int>R(n2 + 1);
  for (int i = 0; i < n2; i++) {
    R.at(i) = A.at(mid + i);
  }

  L.at(n1) = INT_MAX;
  R.at(n2) = INT_MAX;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    // 比較回数をカウントする
    compareCount++;

    if (L.at(i) <= R.at(j)) {
      A.at(k) = L.at(i);
      i = i + 1;
    } else {
      A.at(k) = R.at(j);
      j = j + 1;
    }
  }
}

void mergeSort(vector<int> &A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  // １行目に n、２行目に S を表す n 個の整数が与えられます。 
  int n;
  cin >> n;

  // 配列を受け取る
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
  }

  // マージソートの実行
  mergeSort(S, 0, n);

  // 結果の出力
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }

    cout << S.at(i);
	}
  cout << endl;

  cout << compareCount << endl;
}
