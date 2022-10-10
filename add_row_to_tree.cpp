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
/*
     4
   2   6
  1 1 1  0
 3 1  5 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        if(depth==1)
        {
            TreeNode* rt=new TreeNode(val);
            rt->left=root;
            return rt;
        }
        int c=1;
        q.push(root);
        while(!q.empty() && c<depth)
        {
            int a=q.size();
            c++;
            for(int i=0;i<a;i++)
            {
                auto k=q.front();
                q.pop();
                if(c==depth)
                {
                    if(k->left!=nullptr)
                    {
                        TreeNode* tm=new TreeNode(val);
                        TreeNode* t=k->left;
                        k->left=tm;
                        tm->left=t;
                    }
                    else
                    {
                        TreeNode* tm=new TreeNode(val);
                        k->left=tm;
                    }
                    
                    if(k->right!=nullptr)
                    {
                        TreeNode* tm=new TreeNode(val);
                        TreeNode* t=k->right;
                        k->right=tm;
                        tm->right=t;
                    }
                    else{
                        TreeNode* tm=new TreeNode(val);
                        k->right=tm;
                    }
                }
                else
                {
                    if(k->left!=nullptr)
                        q.push(k->left);
                    if(k->right!=nullptr)
                        q.push(k->right);
                }
            }
        }
        return root;
    }
};
