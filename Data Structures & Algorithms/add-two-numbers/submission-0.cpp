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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        int rem=0;
        ListNode* root=l1;
        ListNode* prev=NULL;
        while(l1!=NULL && l2!=NULL){
            int temp = l1->val + l2->val + rem;

            l1->val = temp%10;
            rem = temp/10;

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2!=NULL){
            prev->next = l2;
            l1 = l2;
        }

        while(l1!=NULL){
            int temp = l1->val + rem;

            l1->val = temp%10;
            rem = temp/10;

            prev = l1;
            l1 = l1->next;
        }

        if(rem!=0){
            ListNode* x = new ListNode(rem);
            prev->next = x;
        }

        return root;
        
    }
};
