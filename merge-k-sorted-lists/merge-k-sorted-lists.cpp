/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return(NULL);
        }
        ListNode* head = new ListNode();
        int k = lists.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++)
        {
            if(lists[i]) pq.push({lists[i]->val,i});
        }
        auto ans = head;
        while(!pq.empty())
        {
            auto least = pq.top();
            pq.pop();
            ListNode* temp = new ListNode(least.first);
            head->next = temp;
            head = head -> next;
            if(lists[least.second]->next)
            {
                lists[least.second] = lists[least.second]->next;
                pq.push({lists[least.second]->val,least.second});
            }
        }
        return(ans->next);
    }
};
