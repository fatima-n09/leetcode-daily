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
        if (headA == NULL || headB == NULL) 
        {
            return NULL;
        }
		ListNode *n = headA;
		ListNode *m = headB;
		while(n!= m){
			if(n== NULL){
				n = headB;
			}
			else{
				n = n -> next;
			}
			if(m == NULL){
				m = headA;
			}
			else{
				m = m -> next;
			}
		}
		return n;
	}
};