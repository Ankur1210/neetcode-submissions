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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;

        head = reverseList(head);

        if(n==1)
            head = head->next;
        else{
            ListNode* prev=NULL;
            ListNode* root=head;
            while(n!=1){
                prev = root;
                root=root->next;
                n--;
            }
            prev->next = root->next;
        }
        
        head = reverseList(head);
        return head;
    }

    ListNode* reverseList(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;

        ListNode* prev = NULL;
        while(head->next!=NULL){
            ListNode* after = head->next;
            head->next = prev;
            prev = head;
            head = after;
        }

        head->next = prev;

        return head;
    }
};
