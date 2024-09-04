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
    bool isPalindrome(ListNode* head) {
        vector<int> val;
        if (!head || !head->next) return true;
        while(head != NULL)
        {
            val.push_back(head->val);
            head = head -> next;
        }
        int left = 0;
        int right = val.size()-1;
        while( left < right && val[left] == val[right])
        {
            left++;
            right--;
        }
        return left >= right;
    }
};