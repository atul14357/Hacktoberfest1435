#include<iostream>
#include<vector>


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void solve(TreeNode* root,int val,int depth)
    {
        int l=2;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();q.pop();
                if(l==depth)
                {
                    TreeNode* n1=new TreeNode(val);
                    TreeNode* n2=new TreeNode(val);
                    if(curr->left)
                    {
                        TreeNode* temp=curr->left;
                        curr->left=n1;
                        n1->left=temp;
                    }
                    else
                        curr->left=n1;
                    if(curr->right)
                    {
                        TreeNode* temp=curr->right;
                        curr->right=n2;
                        n2->right=temp;
                    }
                    else
                        curr->right=n2;
                }
                else
                {
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            }
            l++;
            if(l>depth)
                return;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        solve(root,val,depth);
        return root;
    }
};

int main(){
    
    return 0;
}