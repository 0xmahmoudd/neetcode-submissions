#include <iostream>
#include <algorithm>

using namespace std;

class MinStack
{
private:
    struct Node
    {
        int value;
        int min;
        Node* next;

        Node(int value, int min, Node* next)
            : value(value), min(min), next(next)
        {
        }
    };

    Node* head = nullptr;

public:
    MinStack()
    {
    }

    void push(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value, value, nullptr);
        }
        else
        {
            int currentMin = min(value, head->min);
            head = new Node(value, currentMin, head);
        }
    }

    void pop()
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        return head->value;
    }

    int getMin()
    {
        return head->min;
    }
};

// The key idea is:

// ```text
// value    min
// ----------------
//  -3      -3   <- top
//   0      -2
//  -2      -2
// ```

// Every node remembers **the minimum value from itself down the stack**. So when you pop, you automatically get the previous minimum from the new `head`.

// **O(1)** for every operation.

