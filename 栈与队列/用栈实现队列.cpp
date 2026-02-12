#include <stack>
using namespace std;

class MyQueue {
  stack<int> in, out;

public:
  void push(int x) { in.push(x); }
  int pop() {
    move();
    int v = out.top();
    out.pop();
    return v;
  }
  int peek() {
    move();
    return out.top();
  }
  bool empty() { return in.empty() && out.empty(); }

private:
  void move() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
  }
};
