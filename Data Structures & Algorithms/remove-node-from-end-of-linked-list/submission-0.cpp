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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;

        ListNode*temp=head;
        int len=0;

        //reaching the end of the list
        while(temp){
            temp=temp->next;
            len++;
        }
        
        temp=head;
        int toBeDeleted=len-n+1;
        if(toBeDeleted==1){
            head=head->next;
            return head;
        }

        ListNode*prev=nullptr;
        for(int i=1;i<toBeDeleted;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};
