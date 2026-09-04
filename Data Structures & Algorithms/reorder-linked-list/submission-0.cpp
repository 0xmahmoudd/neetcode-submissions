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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next) return;

        deque<ListNode*> dq;

        ListNode* tmp = head;
        while (tmp)
        {
            dq.push_front(tmp);  // Changed from push_back to push_front
            tmp = tmp->next;
        }

        if (dq.size() == 1) return;

        while (!dq.empty()) 
        {
            if (dq.size() == 1) 
            {
                dq.back()->next = nullptr;
                return;
            }
            
            ListNode* last = dq.back();
            dq.pop_back();
            ListNode* first = dq.front();
            dq.pop_front();
            
            last->next = first;
            
            if (!dq.empty()) 
            {
                first->next = dq.back();
            } 
            else 
            {
                first->next = nullptr; // Important: terminate the list
                break;
            }
        }
    }
};