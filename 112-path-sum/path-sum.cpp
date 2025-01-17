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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return cc(root, targetSum, sum);

        
    }
private:
    bool cc(TreeNode* root, int target, int sum){
        if(root == NULL) return 0;

        sum += root -> val;

        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }

        return cc(root->left, target, sum) || cc(root->right, target, sum);

    }
};