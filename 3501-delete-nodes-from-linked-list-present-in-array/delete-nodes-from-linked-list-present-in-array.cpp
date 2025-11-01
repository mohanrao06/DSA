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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       set<int> st(nums.begin(), nums.end());
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;

        
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                ListNode* nextNode = temp->next;
                prev->next = nextNode;
                // delete temp;
                temp = nextNode;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return dummy->next;
        
    }
};