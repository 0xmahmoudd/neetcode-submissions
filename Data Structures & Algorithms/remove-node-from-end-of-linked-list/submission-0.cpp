/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head) return nullptr;
        int lenght = 0;
        ListNode *tmp = head;

        while (tmp)
        {
            lenght++;
            tmp = tmp->next;
        }

        int lenght_from_start = lenght - n;

        if (lenght_from_start == 0)
        {
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        ListNode *p = head;

        while (--lenght_from_start)
        {
            p = p->next;
        }

        ListNode *q = p->next;

        p->next = q->next;
        q->next = nullptr;

        return head;


    }
};
