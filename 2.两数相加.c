/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *tail = l1;
    struct ListNode *pa = l1;
    while(tail->next)
    {
        tail = tail->next; 
    }
    int ret = 0;
    int sum = 0;
    while (pa && l2)
    {
        sum = ret + pa->val + l2->val;
        ret = sum / 10;
        pa->val = sum % 10;
        pa = pa->next;
        l2 = l2->next;
    }
    while (pa)
    {
        sum = ret + pa->val;
        pa->val = sum % 10;
        ret = sum / 10;
        pa = pa->next;
    }
    while(l2)
    {
        sum = l2->val+ret;
        l2->val = sum%10;
        ret = sum/10;
        tail->next = l2;
        tail = l2;
        l2 = l2->next;
    }
    if (ret)
    {
        struct ListNode *r = (struct ListNode *)malloc(sizeof(struct ListNode));
        r->val = ret;
        tail->next = r;
        r->next = NULL;
    }
    return l1;
}
// @lc code=end
