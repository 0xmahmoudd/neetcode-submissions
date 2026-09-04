/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;

        Node* cur = head;
        // first phase just copy the values in new allocation memory and using hashmap to memorize them
        while (cur)
        {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];

            cur = cur->next;
        }

        return oldToCopy[head];
    }
};
