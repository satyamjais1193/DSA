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
    ListNode* deleteDuplicates(ListNode* head) {
        //dummy node val shoud be out of range 
        ListNode* dummy = new ListNode(-101 , head);

        ListNode* temp = dummy;

        while( temp && temp->next){
            if( temp->next->val == temp->val){
                temp ->next = temp->next->next;
                // temp->next ->next = nullptr;
                
            }
            else{
                temp = temp ->next;
            }
            
            
        }
        return dummy->next;
    }
};