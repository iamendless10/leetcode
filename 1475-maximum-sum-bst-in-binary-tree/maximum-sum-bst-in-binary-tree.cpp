#include <bits/stdc++.h>
using namespace std;


class NodeValue {
public:
    int minnode, maxnode, maxsum;
    bool isBST;

    NodeValue(int minnode, int maxnode, int maxsum, bool isBST) {
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->maxsum = maxsum;
        this->isBST = isBST;
    }
};

class Solution {
private:
    int maxSum = 0; 

    NodeValue cc(TreeNode* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        auto left = cc(root->left);
        auto right = cc(root->right);

      
        if (left.isBST && right.isBST && left.maxnode < root->val && root->val < right.minnode) {
            int sum = left.maxsum + right.maxsum + root->val;
            maxSum = max(maxSum, sum);

            return NodeValue(
                min(root->val, left.minnode),
                max(root->val, right.maxnode),
                sum,
                true
            );
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxsum, right.maxsum), false);
    }

public:
    int maxSumBST(TreeNode* root) {
        cc(root);
        return maxSum;
    }
};
