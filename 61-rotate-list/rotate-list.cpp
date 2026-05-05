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
        if(!head || k==0 )return head;
        
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==1)return head;
        k=k%len;
        if(k == 0) return head; 
        ListNode* curr=head;
        for(int i=1;i<len-k;i++){
            curr=curr->next;
        }
        ListNode* nextNode=curr->next;
        curr->next=NULL;
        ListNode* newhead=nextNode;
        ListNode* lastNode=nextNode;
        while(lastNode->next){
            lastNode=lastNode->next;
        }
        lastNode->next=head;
        return newhead;
    }
};