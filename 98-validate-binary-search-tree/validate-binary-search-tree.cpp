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
    bool isValid(TreeNode* root, TreeNode* leftNode, TreeNode* rightNode) {
        if (root == nullptr)
            return true;

        if (leftNode != nullptr && root->val <= leftNode->val)
            return false;

        if (rightNode != nullptr && root->val >= rightNode->val)
            return false;

        return isValid(root->left, leftNode, root) &&
               isValid(root->right, root, rightNode);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};