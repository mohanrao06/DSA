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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even=new ListNode(-1);
        ListNode* odd=new ListNode(-1);
        ListNode* evenptr=even;
        ListNode* oddptr=odd;
        ListNode* curr=head;
        int cnt=1;
        while(curr){
            if(cnt%2==0){
                evenptr->next=curr;
                evenptr=evenptr->next;
            }else{
                oddptr->next=curr;
                oddptr=oddptr->next;
            }
            curr=curr->next;
            cnt++;
        }
        evenptr->next=NULL;
        oddptr->next=even->next;

        return odd->next;
    
    }
};