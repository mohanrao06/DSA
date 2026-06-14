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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;

    }
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(n==2){
            return head->val+head->next->val;
        }
        int half=(n/2)-1;
        int i=0;
        temp=head;
        for(int i=0;i<half;i++){
            temp=temp->next;
        }
        ListNode* sec=temp->next;
        temp->next=NULL;
        ListNode* newhead=reverse(sec);

        ListNode* l=head;
        ListNode* r=newhead;
        int ans=0;
        while(l && r){
            ans=max(ans,l->val+r->val);
            l=l->next;
            r=r->next;
        }
        return ans;







    }
};