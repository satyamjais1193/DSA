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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        //count length of list
        int count = 0;
        while(fast){
            count ++;
            fast = fast->next;
        }
        //update k
        k = k%count;

        if(k==0 )return head;

        fast = head;

        // creating gap of k 
        for(int i =0; i< k; i++){
            fast = fast->next;
        }

        //moving with gap
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        //now rearrange to give rotated list
        fast->next = head;
        head = slow->next;

        slow->next = nullptr;
        return head;


    }
};