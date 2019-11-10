/**
 * Queue
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=ja
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Process {
  string name;
  int time;
};

int main() {
  int N, q;
  cin >> N >> q;

  // プロセスの格納
  vector <Process>queue(N);
  for (int i = 0; i < N; i++) {
    cin >> queue.at(i).name >> queue.at(i).time;
  }

  int time = 0;

  // プロセスが残っている間は続ける
  while (queue.size() > 0) {
    // キューの先頭からプロセスをひとつ取り出す
    Process p = queue.front();
    queue.erase(queue.begin(), queue.begin() + 1);

    if (p.time > q) {
      // 100msをプロセスで消費させて、キューの末尾で順番待ちさせる
      time += q;
      p.time -= q;
      queue.push_back(p);
    } else {
      time += p.time;
      cout << p.name << ' ' << time << endl;
    }
  }

  return 0;
}

