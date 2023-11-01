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

    void inorder(TreeNode* root, vector<int> &res){
        if(!root){
            return;
        }
        res.push_back(root->val);
        inorder(root->left, res);
        inorder(root->right, res);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> inorderr;
        inorder(root, inorderr);
        unordered_map<int, int> freq;
        int maxx = 0;

        for(int val : inorderr){
            freq[val]++;
            maxx = max(maxx, freq[val]);
        }
        vector<int> res;
        for(const auto& pair : freq){
            if(pair.second == maxx){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};