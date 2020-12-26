/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
​
class Solution {
public:
    Node* flatten(Node* head) {
        Node* ans = head;
        while(head)
        {
            if(head->child)
            {
                Node* next  = head->next;
                head->next = head->child;
                head->child->prev = head;
                head->child =  NULL;
                Node* tail = head->next;
                while(tail->next) tail = tail->next;
                tail->next = next;
                if(next) next->prev = tail;
            }
            head = head->next;
        }
        return(ans);
    }
    
};
