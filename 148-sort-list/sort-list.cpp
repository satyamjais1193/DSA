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
    ListNode* getmiddle(ListNode* head){
        ListNode* slow = head;
        //fast is one step ahead of slow to n/2 -1 wala middle
        //so that we could get direclty next head of next part by slow->next
        ListNode* fast = head ->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast ->next->next;
        }
        return slow;
    }

    //to merge tow sorted llist
    ListNode* sortedMerge(ListNode* head1, ListNode* head2) {
        // code here
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(head1 && head2){
            if( head1->val <= head2->val){
                curr->next= head1;
                head1 = head1->next;
            }
            else{
                curr->next = head2;
                head2 = head2->next;
            }
            curr= curr->next;
        }
        
        //adding left part;
        if(head1){
            curr->next = head1;
        }
        else{
            curr->next = head2;
        }
        return dummy->next;
    }

    ListNode* mergesort( ListNode* head){
        if(!head || !head->next) return head;

        //dividing into two part
        ListNode* middle = getmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;

        //yaha galti hoti hai--- to seprate left and right part
        middle->next = nullptr;

        ListNode* leftsort = mergesort(lefthead);
        ListNode* rightsort = mergesort(righthead);

        return sortedMerge(leftsort, rightsort);

    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};