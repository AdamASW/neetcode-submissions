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
    int max_diameter = 0;

    int heightOfBinaryTree(TreeNode* root) {
        int right_height, left_height;
        if (root->right && root->left) {
            right_height = 1 + heightOfBinaryTree(root->right);
            left_height = 1 + heightOfBinaryTree(root->left);
        }
        else if (root->right) {
            right_height = 1 + heightOfBinaryTree(root->right);
            left_height = 0;
        }
        else if (root->left) {
            right_height = 0;
            left_height = 1 + heightOfBinaryTree(root->left);
        }
        else {
            return 0;
        }
        
        int curr_diameter = right_height + left_height;
        if (curr_diameter > max_diameter) {
            max_diameter = curr_diameter;
        }
        return max({left_height, right_height});
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_height = heightOfBinaryTree(root);
        return max_diameter;
    }
};
