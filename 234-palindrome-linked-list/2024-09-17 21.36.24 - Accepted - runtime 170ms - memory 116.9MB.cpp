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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=slow;
        slow->next=NULL;
        while(curr){
            ListNode* nxtptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxtptr;
        }
        ListNode* head1=head;
        ListNode* head2=prev;
        while(head2){
            if(head1->val != head2->val){
                return false;
                break;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;



       


    }
};