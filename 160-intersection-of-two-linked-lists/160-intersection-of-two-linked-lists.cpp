/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizea = 0;
        int sizeb = 0;
        auto tempa = headA;
        auto tempb = headB;
        while(tempa != NULL)
        {
            tempa = tempa->next;
            sizea++;
        }
        while(tempb != NULL)
        {
            tempb = tempb->next;
            sizeb++;
        }
        int diff = abs(sizea-sizeb);
        if(sizea < sizeb)
        {
            swap(headA,headB);
        }
        tempa = headA;
        tempb = headB;
        cout << sizea << " " << sizeb << " " << diff << endl;
        while(diff--)
        {
            tempa = tempa->next;
        }
        cout << tempa->val << endl;
        if(tempa == tempb)
                return tempa;
        while(tempa->next && tempb->next)
        {
            if(tempa == tempb)
                return tempa;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        if(tempa == tempb)
                return tempa;
        return NULL;
        
    }
};