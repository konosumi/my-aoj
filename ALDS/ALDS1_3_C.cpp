/**
 * Doubly Linked List
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C&lang=ja
 */

#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

void trace(list <int>lst) {
  cout << lst.front();
  for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
    if (itr == lst.begin()) {
      continue;
    }
    cout << ' ';
    cout << *itr;
  }

  cout << endl;

  /*
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
  */
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  // プロセスの格納
  string command;
  int number;
  list <int>lst;
  for (int i = 0; i < N; i++) {
    cin >> command;
    if (command == "insert") {
      cin >> number;
      lst.push_front(number);
    } else if (command == "delete") {
      cin >> number;
      for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
        if (*itr == number) {
          lst.erase(itr);
          break;
        }
      }
    } else if (command == "deleteFirst") {
      lst.pop_front();
    } else if (command == "deleteLast") {
      lst.pop_back();
    }
  }

  trace(lst);

  return 0;
}
