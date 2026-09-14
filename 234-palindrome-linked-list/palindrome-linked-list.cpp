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
    //to revrese list
    ListNode* solve(ListNode* prev, ListNode* curr) {

        //retruing prev as head...as when curr rech to nullptr after travelling all LL.. and at that prev will be denoting newhead of reversed linked list ... thus return prev
        if(!curr) return prev;

        //ek base mai kerunga
        ListNode* nextnode = curr->next;
        curr->next = prev;

        //baki recurion dekh lega
        return solve( curr, nextnode);
    }



    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        //travel till mid point to divide it into two list
        while(fast->next){
            fast = fast -> next ;
            if(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }

        //make tow list
        ListNode* head1 = head;
        ListNode* head2 = slow->next;

        //main condition 


        //reverse list2 
        head2 = solve(nullptr, head2);

        while( head2){
            if(head2->val != head1->val) return false;

            head2 = head2->next;
            head1= head1->next;
        }
        return true;



    }
};