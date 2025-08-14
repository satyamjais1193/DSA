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
        vector<bool> present(203, false);

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode * nextNode = curr->next;
            if(present[curr->val + 100]){
                prev->next = nextNode;
                curr->next = NULL;
                // delete curr;

                // prev->next = nextNode;
                curr = nextNode;
                
                
            }
            else{
                present[curr->val + 100] = true;
                            prev = curr;
            curr = nextNode;
                
            }
            // prev = curr;
            // curr = nextNode;

        }
        return head;
    }
};