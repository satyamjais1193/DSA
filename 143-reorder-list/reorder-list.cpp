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
    void reorderList(ListNode* head) {
        //3 opration -- find middle --- reverse second--- add altrenate

        //find middle and break into tow
        ListNode* fast = head;
        ListNode* slow = head;

        while( fast->next){
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        // cout<<head2->val<<endl;

        //reverse 2nd part
        ListNode* curr= head2;

        ListNode* prev = nullptr;

        while(curr){
            ListNode* nextnode= curr->next;
            curr->next = prev;
            prev= curr;
            curr = nextnode;
        }

        head2 = prev;
        // while( head2){
        //     cout<<head2->val<<" ";
        //     head2= head2->next;
        // }

        //add alternate
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while( temp2){
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2 ->next;

            temp1->next = temp2;
            temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }



    }
};