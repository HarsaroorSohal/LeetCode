/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return(root);
        queue<Node*> q1,q2;
        q1.push(root);
        vector<Node*> level,next_level;
        level.push_back(root);
        while(!q1.empty())
        {
            auto curr = q1.front();
            q1.pop();
            if(curr->left)
            {
                q2.push(curr->left);
                next_level.push_back(curr->left);
            }
            if(curr->right)
            {
                q2.push(curr->right);
                next_level.push_back(curr->right);
            }
            if(q1.empty())
            {
                for(int i=0;i<level.size();i++)
                {
                    auto node = level[i];
                    if(node == level.back())
                        node->next = NULL;
                    else
                        node->next = level[i+1];
                }
                swap(q1,q2);
                level.clear();
                swap(next_level,level);
            }
            
        }
        return(root);
    }
};