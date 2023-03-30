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
    int preindex=0;
    TreeNode* ctree(vector<int>& preorder, vector<int>& inorder,int is, int ie)
     {
        if(is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[preindex++]);
        int inindex;
        for(int i=is;i<=ie;i++)
        {
            if( inorder[i]==root->val)
            {
                inindex=i;
                break;
                
            }
        }
        root->left=ctree( preorder,  inorder, is, inindex-1);
        root->right=ctree( preorder,  inorder, inindex+1, ie);
        return root;

     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      //  vector<int>& preorder;
      //  vector<int>& inorder;
        int is=0;
        int ie=inorder.size()-1;
        
       TreeNode* curr=   ctree( preorder,  inorder, is, ie);
        return curr;
    }
};