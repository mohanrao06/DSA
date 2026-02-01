/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=length(headA);
        int m=length(headB);
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(m>n){
            int k=m-n;
            while(k--){
                tempB=tempB->next;
            }

        }else{
            int k=n-m;
            while(k--){
                tempA=tempA->next;
            }
        }
        while(tempA && tempB){
            if(tempA==tempB)return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;


    }
    int length(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
};