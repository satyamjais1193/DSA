/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //copy next node data
        node->val = node->next->val;

        //skip next node;
        ListNode* todel = node->next;
        node->next = todel->next;

        //This method cannot delete the last node.-- as mention in question

    }
};