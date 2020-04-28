/**
 * Stable Sort
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_C&lang=ja
 */

#include<bits/stdc++.h>
using namespace std;

void trace(vector <string>A) {
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

/**
 * バブルソートを実行する
 */
vector<string> bubble(vector<string>A, int N) {
  // int count = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = N - 1; j > 0; j--) {
      // より小さい要素を先頭に移動していく
      if (A.at(j)[1] < A.at(j - 1)[1]) {
        swap(A.at(j), A.at(j - 1));
        // count++;
        flag = true;
        // trace(A);
      }
    }
  }
  return A;
}

/**
 * 選択ソートを実行する
 */
vector<string> selection(vector<string>A, int N) {
  // int count = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    // 最小要素の位置を探索する
    for (int j = i; j < N; j++) {
      if (A.at(j)[1] < A.at(minj)[1]) {
        minj = j;
      }
    }

    // 最小要素を未ソート配列の先頭に移動する
    if (i != minj) {
      swap(A.at(i), A.at(minj));
      // count++;
    }
  }

  return A;
}

/**
 * ソートが安定的かどうかを判定する
 */
string isStable(vector<string>A, vector<string>S, int N) {
  // int count = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < S.size(); j++) {
      // 一致する要素が登場したら、一致した要素は安定的であるとして削除する
      if (S.at(j) == A.at(i)) {
        S.erase(S.begin() + j, S.begin() + j + 1);
        break;
      }
      // 一致する要素が登場する前に、数字が同じ他のカードが登場してしまった
      if (A.at(i)[1] == S.at(j)[1]) {
        return "Not stable";
      }
    }
  }

  return "Stable";
}

int main() {
  int N;
  cin >> N;

  vector <string>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  // trace(A);

  vector <string>B = bubble(A, N);
  vector <string>S = selection(A, N);

  // バブルソートの結果を出力する
  trace(B);
  cout << isStable(A, B, N) << endl;

  // 選択ソートの結果を出力する
  trace(S);
  cout << isStable(A, S, N) << endl;
  // cout << count << endl;
}
