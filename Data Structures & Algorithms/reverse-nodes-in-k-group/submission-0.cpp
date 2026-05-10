class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            // Not enough nodes
            if (!kth) {
                break;
            }

            ListNode* groupNext = kth->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {

                ListNode* tmp = curr->next;

                curr->next = prev;

                prev = curr;

                curr = tmp;
            }

            // Reconnect
            ListNode* tmp = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = tmp;
        }

        return dummy.next;
    }
};