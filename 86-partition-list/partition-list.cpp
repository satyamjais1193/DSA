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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessdummy = new ListNode( -201);
        ListNode* greaterdummy = new ListNode( -201);

        ListNode* less = lessdummy;
        ListNode* grt = greaterdummy;

        ListNode* temp = head;

        while( temp){
            if(temp->val < x){
                less->next = temp;
                less = less ->next;
            }
            else{
                grt ->next = temp;
                grt = grt ->next;
            }
            temp = temp->next;
        }

        less->next = greaterdummy->next;
        grt->next = nullptr;

        return lessdummy->next;

    }
};