/**
 * Stack
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=ja
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  // int N;
  // cin >> N;

  // 計算途中の値を入れておく
  vector <int>stack(100);

  while (1) {
    string s;
    cin >> s;
    // 入力が終了したら完了とする
    if (cin.eof()) {
      break;
    }
    if (s == "+" || s == "-" || s == "*") {
      // 演算対象の数値を2つ取り出す
      int b = stack.back();
      stack.pop_back();
      int a = stack.back();
      stack.pop_back();

      if (s == "+") {
        stack.push_back(a + b);
      }
      if (s == "-") {
        stack.push_back(a - b);
      }
      if (s == "*") {
        stack.push_back(a * b);
      }
    } else {
      // stoiが使えるのは、c++11以降である
      stack.push_back(stoi(s));
    }
  }

  cout << stack.back() << endl;
  return 0;
}

