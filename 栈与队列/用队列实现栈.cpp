#include <queue>
using namespace std;

class MyStack {
  queue<int> q;

public:
  void push(int x) {
    int n = q.size();
    q.push(x);
    while (n--) {
      q.push(q.front());
      q.pop();
    }
  }
  int pop() {
    int v = q.front();
    q.pop();
    return v;
  }
  int top() { return q.front(); }
  bool empty() { return q.empty(); }
};
