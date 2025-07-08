/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }

    bool valid(TreeNode* root, TreeNode*  minNode, TreeNode* maxNode) {
        if (!root) {
            return true;
        }
        if ((minNode != nullptr && root->val <= minNode-> val ) || (maxNode != nullptr && root->val >= maxNode-> val)) {
            return false;
        }
        return valid(root-> left, minNode, root) && 
        valid(root-> right, root, maxNode);
         
    }
};