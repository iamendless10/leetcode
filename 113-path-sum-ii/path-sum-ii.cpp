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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum =0;
        vector<vector<int>> res;
        vector<int> ds;
        cc(root, targetSum, sum,res, ds);
        return res;
        
    }
private:
    void cc(TreeNode* root, int target, int sum, vector<vector<int>> &res, vector<int> &ds){
        if (root == NULL) return;

        sum += root -> val;
        ds.push_back(root -> val);

        if (root -> left == NULL && root -> right == NULL && sum == target){
            res.push_back(ds);
        }

        cc(root -> left,target,sum,res,ds);
        cc(root -> right, target, sum,res,ds);
        ds.pop_back();
    }
};