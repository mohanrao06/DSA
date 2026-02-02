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
    ListNode* KthNode(ListNode* head,int k){
        ListNode* temp=head;
        k=k-1;
        while(k-- && temp){
            temp=temp->next;
        }
        return temp;
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* kthNode=KthNode(temp,k);
            if(kthNode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* reverseNode=reverseList(temp);
            if(temp==head){
                head=reverseNode;
            }else{
                prev->next=reverseNode;
            }
            prev=temp;
            temp=nextNode;


        }
        return head;
        
    }
};