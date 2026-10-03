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
    int height(TreeNode* root) {
        if (!root) { return 0; }
        int left_height;
        int right_height;
        if (root->right && root->left) {
            left_height = height(root->left);
            right_height = height(root->right);
            if (left_height == -1 || right_height == -1) { return -1; }
            left_height++; right_height++;
        }
        else if (root->right) {
            left_height = 0;
            right_height = height(root->right);
            if (right_height == -1) { return -1; }
            right_height++;
        }
        else if (root->left) {
            left_height = height(root->left);
            right_height = 0;
            if (left_height == -1) { return -1;}
            left_height++;
        }
        else {
            return 0;
        }
        if (((left_height - right_height)*(left_height - right_height)) > 1) {
            return -1;
        }
        return max({left_height, right_height});
    }

    bool isBalanced(TreeNode* root) {
        int max_height = height(root);
        if (max_height == -1) {
            return false;
        }
        return true;
    }
};
