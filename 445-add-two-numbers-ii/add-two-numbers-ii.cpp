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
    ListNode* reverse(ListNode* prev, ListNode* curr){
        if(!curr) return prev;

        ListNode* nextnode = curr->next;
        curr->next = prev;

        return reverse(curr, nextnode);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reversed list for addition
        ListNode* rl1 = reverse(nullptr, l1);
        ListNode* rl2 = reverse( nullptr, l2);

        // create dummy node to store new list formed/
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry  = 0;

        //run loop until any of rl1 or rl2 or carry exits and made new node to store next calcutaion...
        while( rl1 || rl2 || carry){
            int v1 = (rl1) ? rl1->val : 0;
            int v2 = (rl2) ? rl2->val : 0;

            int num = v1 + v2 + carry;

            curr -> next = new ListNode( num %10);
            curr = curr->next;
            carry = num /10;

            //move rl1 and rl2 if thier next value exits
            if(rl1) rl1  = rl1 ->next;
            if(rl2) rl2 = rl2 ->next;
        }
        //reverse and return ans
        return reverse(nullptr, dummy->next);

    }
};