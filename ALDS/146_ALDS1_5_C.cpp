/**
 * Koch Curve
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x;
  double y;
};

void printPoint(Point p) {
  printf("%.8f %.8f", p.x, p.y);
  cout << endl;
}

void koch(int n, Point p1, Point p2) {
  if (n == 0) {
    return;
  }

  // 度からラジアンへ単位を変換
  double th = M_PI * 60.0 / 180.0;

  Point s, t, u;
 	s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
	s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;

	t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
	t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;

	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  // p1とsの間にコッホ曲線を描く
  koch(n - 1, p1, s);
  printPoint(s);
  // sとuの間にコッホ曲線を描く
  koch(n - 1, s, u);
  printPoint(u);
  // uとtの間にコッホ曲線を描く
  koch(n - 1, u, t);
  printPoint(t);
  // tとp2の間にコッホ曲線を描く
  koch(n - 1, t, p2);
}

int main() {
  // 深さn
  int n;
  cin >> n;

  Point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  // 始点の出力
  printPoint(a);
  koch(n, a, b);
  // 終点の出力
  printPoint(b);
}
