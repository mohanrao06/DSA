class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* kthnode = getKthNode(temp, k);
            if (kthnode == NULL) {
                if (prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kthnode->next;
            kthnode->next = NULL;
            ListNode* newHead = reverse(temp);  // correct use

            if (temp == head) {
                head = newHead;  // use newHead, not kthnode
            } else {
                prev->next = newHead;  // use newHead, not kthnode
            }

            prev = temp;       // temp is now the tail of reversed group
            temp = nextNode;   // move to the next group
        }

        return head;
    }
};
