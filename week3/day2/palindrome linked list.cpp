class Solution {
public:

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = slow->next;

        // Compare both halves
        while(second) {

            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
