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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int n =0; 
        while(temp){
            temp = temp ->next;
            n++;
        }

        int k = (n)/2;

        ListNode* prev= nullptr;
        ListNode* curr = head;

        for(int i=0; i<k; i++){
            ListNode* nextNode = curr->next;
            curr->next= prev;
            prev = curr;
            curr= nextNode;            
        }

        ListNode* head1 = prev;
        ListNode* head2 = curr;

        if (n % 2 == 1)
            head2 = head2->next;

        while(head2){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};