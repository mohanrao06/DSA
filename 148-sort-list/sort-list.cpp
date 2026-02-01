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
    ListNode* mergeLL(ListNode* head1,ListNode* head2){
        ListNode* dummy=new ListNode(-1);
        ListNode* dhead=dummy;
        ListNode* left=head1;
        ListNode* right=head2;
        while(left && right){
            if(left->val<right->val){
                dummy->next=left;
                
                left=left->next;
            }
            else{
                dummy->next=right;
                
                right=right->next;
            }
            dummy=dummy->next;
            
           
        }
        if(left){
            dummy->next=left;
        }else{
            dummy->next=right;
        }
        return dhead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle=findmiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* leftHead=sortList(left);
        ListNode* rightHead=sortList(right);
        return mergeLL(leftHead,rightHead);

    }
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};