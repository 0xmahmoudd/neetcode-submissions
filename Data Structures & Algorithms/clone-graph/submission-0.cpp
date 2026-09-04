/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
private:

unordered_map<Node*, Node*> copies;

public:

    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr;
        
        Node* copy = new Node(node->val);
        copies[node] = copy;

        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();

            for (Node* neighbour : cur->neighbors)
            {
                if (copies.find(neighbour) == copies.end())
                {
                    copies[neighbour] = new Node(neighbour->val);

                    q.push(neighbour);
                }

                copies[cur]->neighbors.push_back(copies[neighbour]);
            }
        }

        return copy;

    }
    
};
