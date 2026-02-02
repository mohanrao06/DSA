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
   ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return last;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        temp=head;
        k = k % len;
        if (k == 0) return head;
        int n=len-k;
        for (int i = 1; i < n; i++) {
            temp = temp->next;
        }
        ListNode* nextNode=temp->next;
        temp->next=NULL;
        ListNode* curr=nextNode;
        while(curr->next){
            curr=curr->next;
        }
        

        curr->next=head;
        head=nextNode;
        return nextNode;
    }
};