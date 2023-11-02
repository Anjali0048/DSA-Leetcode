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
    int res = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }
    pair<int, int> postorder(TreeNode* node){
        if(!node){
            return {0,0};
        }
        auto left = postorder(node->left);
        auto right = postorder(node->right);

        int totalSum = left.first + right.first + node->val;
        int totalCount = 1 + left.second + right.second;
        res += (node->val == totalSum / totalCount);

        return {totalSum, totalCount};
    } 
};