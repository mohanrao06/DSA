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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        int n=0;
        if(head==NULL)return NULL;
        while(tail){
            n++;
            tail=tail->next;

        }
        
        k=k%n;
        if(k==0)return head;
        ListNode* temp=head;
        for(int i=1;i<n-k;i++){
            temp=temp->next;

        }
        ListNode* newHead=temp->next;
        ListNode* temp2=temp->next;
        temp->next=NULL;
        
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=head;
        return newHead;

    }
};