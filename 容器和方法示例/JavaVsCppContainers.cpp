#include <bits/stdc++.h>
using namespace std;

int main() {
  // Array vs vector size
  vector<int> v = {1, 2, 3};
  cout << "vector size(): " << v.size() << endl;

  // string size / length
  string s = "hello";
  cout << "string size(): " << s.size() << endl;
  cout << "string length(): " << s.length() << endl;

  // vector access and set
  cout << "v[1] before: " << v[1] << endl;
  v[1] = 99;
  cout << "v[1] after: " << v[1] << endl;

  // map access vs find
  unordered_map<string, int> mp;
  // mp["a"] will insert default 0
  mp["a"]++;
  cout << "mp['a'] = " << mp["a"] << endl;

  if (mp.count("b")) {
    cout << "b exists" << endl;
  } else {
    cout << "b not exists (no insertion)" << endl;
  }

  // set count
  unordered_set<int> st;
  st.insert(5);
  cout << "set contains 5: " << (st.count(5) ? "yes" : "no") << endl;

  // stack pop does not return
  stack<int> st2;
  st2.push(10);
  int top = st2.top();
  st2.pop();
  cout << "stack top was: " << top << endl;

  // queue pop does not return
  queue<int> q;
  q.push(1);
  int front = q.front();
  q.pop();
  cout << "queue front was: " << front << endl;

  // priority_queue pop does not return
  priority_queue<int> pq;
  pq.push(3);
  pq.push(7);
  int best = pq.top();
  pq.pop();
  cout << "priority_queue top was: " << best << endl;

  // string find returns npos
  size_t pos = s.find("ll");
  if (pos != string::npos) {
    cout << "find 'll' at: " << pos << endl;
  }

  return 0;
}
