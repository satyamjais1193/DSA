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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //can be done by using set/map by cheaking it alredy present or not

        //method-2
        // 🔥 Trick: Pointer Switching

        // Use p1 and p2.

        // When p1 reaches the end, move it to headB.

        // When p2 reaches the end, move it to headA.

        // p1: A + B
        // p2: B + A

        // Now both travel the same total distance.
        //  thus they meet each other at intersection point

        ListNode* p1= headA;
        ListNode* p2 = headB;

        while(p1 != p2){
            p1 = (p1== nullptr)? headB : p1 ->next;
            p2= ( p2== nullptr)? headA : p2->next;
        }
        return p1;



    }
};