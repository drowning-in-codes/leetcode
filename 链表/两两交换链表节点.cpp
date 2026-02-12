struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode* a = cur->next;
            ListNode* b = cur->next->next;
            a->next = b->next;
            b->next = a;
            cur->next = b;
            cur = a;
        }
        return dummy.next;
    }
};
