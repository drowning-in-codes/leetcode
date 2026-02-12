struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast = &dummy;
    ListNode *slow = &dummy;
    for (int i = 0; i < n; ++i)
      fast = fast->next;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *del = slow->next;
    slow->next = del->next;
    return dummy.next;
  }
};
