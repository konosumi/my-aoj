/**
 * Areas on the Cross-Section Diagram
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D&lang=ja
 * 参考：Areas on the Cross-Section Diagram 解き方メモ
 * https://mtdtx9.hatenablog.com/entry/2017/04/24/230941
 */

#include<iostream>
#include<stack>
using namespace std;

struct Area {
  int index;
  int size;
};

Area mkArea(int index, int size) {
  Area area = Area();
  area.index = index;
  area.size = size;
  return area;
}

void trace(stack <Area>A) {
  stack <Area>B;
  while (A.size()) {
    B.push(A.top());
    A.pop();
  }

  while (B.size() > 0) {
    cout << ' ' << B.top().size;
    B.pop();
  }
}

int areaTotalSize(stack <Area>A) {
  int size = 0;
  while (A.size() > 0) {
    Area area = A.top();
    A.pop();
    size += area.size;
  }

  return size;
}

int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(false);

  stack <Area>areaStack;
  stack <int>slopeIndexStack;
  char slope;
  int index = -1;
  while (++index <= 20000) {
    cin >> slope;
    if (cin.eof()) {
      break;
    } else if (slope == '\\') {
      slopeIndexStack.push(index);
    } else if (slope == '/') {
      if (slopeIndexStack.empty()) {
        continue;
      }

      int slopeIndex = slopeIndexStack.top();
      slopeIndexStack.pop();
      Area area = mkArea(slopeIndex, index - slopeIndex);
      while (areaStack.size() > 0) {
        Area areaTop = areaStack.top();
// cout << "area top index " << areaTop.size << " " << areaTop.index <<  endl;
        if (areaTop.index > area.index) {
          areaStack.pop();
          area.size += areaTop.size;
        } else {
          break;
        }
      }
      areaStack.push(area);
    }
  }

  cout << areaTotalSize(areaStack) << endl;
  cout << areaStack.size();
  trace(areaStack);
  cout << endl;

  return 0;
}
