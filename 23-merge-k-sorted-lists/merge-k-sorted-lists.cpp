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
    ListNode* mergeKLists(ListNode* l1,ListNode* l2){
        ListNode* dummy =new ListNode(-1);
        ListNode*  head=dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                head->next=l1;
                l1=l1->next;
            }else{
                head->next=l2;
               
                l2=l2->next;
            }
            head = head->next;
        }
        
       if(l1)head->next=l1;
       if(l2)head->next=l2;
       return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        while(lists.size()>1){
            ListNode* l1=lists[0];
            ListNode* l2=lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            ListNode* newll=mergeKLists(l1,l2);
            lists.push_back(newll);
        }
        return lists[0];
    }
};