/**
 * Areas on the Cross-Section Diagram
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D&lang=ja
 */

#include<iostream>
#include<stack>
#include<list>
using namespace std;

/*
void trace(stack <char>A) {
  stack <char>B;
  while (A.size()) {
    B.push(A.top());
    A.pop();
  }

  while (B.size()) {
    cout << B.top();
    B.pop();
  }
 
  cout << endl;
}
*/

struct Area {
  int size;
  int distance;
  bool isFreeze;
};

int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(false);

  stack <char>slopeStack;
  stack <Area>areaStack;
  char slope;
  while (true) {
    cin >> slope;
    if (cin.eof()) {
      break;
    } else if (slope == '\\') {
      slopeStack.push(slope);
    } else if (slope == '_') {
      if (slopeStack.size()) {
        slopeStack.push(slope);
      }
    } else if (slope == '/') {
      if (slopeStack.empty()) {
        continue;
      }
      Area area = Area();
      area.size = 0;
      area.distance = 0;
      if (areaStack.size() > 0) {
        Area area2 = areaStack.top();
        if (!area2.isFreeze) {
          area = area2;
          areaStack.pop();
        }
      }

      while (slopeStack.size() > 0) {
        char slopeTop = slopeStack.top();
        slopeStack.pop();
        if (slopeTop == '_') {
          area.distance++;
        } else if (slopeTop == '\\') {
          area.size += area.distance + 1;
          area.distance += 2;
          break;
        }
      }

      area.isFreeze = slopeStack.empty();
      areaStack.push(area);
    }
  }

  int total = 0;
  stack <int>areaSize;
  while (areaStack.size() > 0) {
    Area area = areaStack.top();
    areaStack.pop();
    total += area.size;
    areaSize.push(area.size);
  }
  cout << total << endl;
  
  cout << areaSize.size();
  while (areaSize.size() > 0) {
    cout << ' ' << areaSize.top();
    areaSize.pop();
  }
  cout << endl;

  return 0;
}
