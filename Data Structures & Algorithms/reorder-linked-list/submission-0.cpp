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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return ;
        
        ListNode *second = findMiddle(head);
        ListNode *after = second->next;
        second->next = NULL;
        second = after;

        second = reverseList(second);
        ListNode* temp = second;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }

        ListNode* first=head;

        while(first!=NULL && second!=NULL){
            after=first->next;
            first->next = second;
            first = after;
            ListNode* after2 = second->next;
            second->next = first;
            second = after2;
        }

        return ;
        
    }

    ListNode* findMiddle(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *tor = head;
        ListNode *hare = head->next;
        int loopsNo = 0;

        while(hare!=NULL && hare->next!=NULL){
            hare = hare->next->next;
            tor = tor->next;
        }

        return tor;
    }

    ListNode *reverseList(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;

        ListNode* prev= NULL;
        while(head->next!=NULL){
            cout<<head->val<<" ";
            ListNode* after = head->next;
            head->next = prev;
            prev=head;
            head=after;
        }

        head->next=prev;

        cout<<endl;

        return head;
    }
};
