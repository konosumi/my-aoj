/**
 * Dictionary
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
 */

#include<iostream>
#include<map>
using namespace std;

int main() {
  int n;
  cin >> n;

  string cmd, val;
  map<string, int> dic; // <key, value> と書くとkey型をキーとし、value型を値とする。
  for (int i = 0; i < n; i++) {
    cin >> cmd >> val;
    if (cmd == "insert") {
      dic[val] = 1;
    } else if (cmd == "find") {
	    cout << (dic.find(val) != dic.end() ? "yes" : "no") << endl;
    }
  }
  return 0;
}
