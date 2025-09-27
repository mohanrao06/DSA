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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        ListNode* dummyHead=new ListNode(-1);
        ListNode* temp=dummyHead;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;

            }else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
            
            
        }
        if(temp1)temp->next=temp1;
        else temp->next=temp2;
        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* middle=findMiddle(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=NULL;
        ListNode* leftsort = sortList(leftHead);
        ListNode* rightsort = sortList(rightHead);
        return merge(leftsort,rightsort);
    }
};