i/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)    return true;
        vector<int> tmp;
        inorder(root, tmp);
        
        bool flag = true;
        int _size = tmp.size();
        for(int i=1; i<_size; ++i){
            if(tmp[i-1] >= tmp[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
private:
    void inorder(TreeNode* root, vector<int>& tmp){
        if(root == NULL)    return ;
        inorder(root->left, tmp);
        tmp.push_back(root->val);
        inorder(root->right, tmp);
    }
};

