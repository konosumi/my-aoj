/**
 * Queue
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=ja
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Process {
  string name;
  int time;
};

int main() {
  int N, q;
  cin >> N >> q;

  // プロセスの格納
  queue <Process>queues;
  for (int i = 0; i < N; i++) {
    Process p = Process();
    cin >> p.name >> p.time;
    queues.push(p);
  }

  int time = 0;
  // プロセスが残っている間は続ける
  while (queues.size() > 0) {
    // キューからプロセスをひとつ取り出す
    Process p = queues.front();
    queues.pop();

    if (p.time > q) {
      // qmsをプロセスで消費させて、キューの末尾で順番待ちさせる
      time += q;
      p.time -= q;
      queues.push(p);
    } else {
      time += p.time;
      cout << p.name << ' ' << time << endl;
    }
  }

  return 0;
}
