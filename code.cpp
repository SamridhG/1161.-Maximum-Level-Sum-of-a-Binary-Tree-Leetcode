3 Approach

1 Approch

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>level;
        vector<int>Sum;
        level.push(root);
        Sum.push_back(-1000000);
        int lvl=0;
        int ans=0;
        while(!level.empty())
        {
            lvl++;
            int size=level.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=level.front();
                level.pop();
                sum+=node->val;
                if(node->left){level.push(node->left);}
                if(node->right){level.push(node->right);}
            }
            int res=Sum.back();
            Sum.pop_back();
                if(sum>res)
                {
                    Sum.push_back(sum);
                    ans=lvl;
                }
                else
                {
                     Sum.push_back(res);
                }
          }
      return ans;   
    }
};
2nd Approach

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>level;
        vector<int>Sum;
        level.push(root);
        while(!level.empty())
        {
            int size=level.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=level.front();
                level.pop();
                sum+=node->val;
                if(node->left){level.push(node->left);}
                if(node->right){level.push(node->right);}
            }
          }
        
        int i=*max_element(Sum.begin(),Sum.end());
        return (find(Sum.begin(),Sum.end(),i)-Sum.begin())+1;
    }
};
3rd Approach

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>level;
        vector<int>Sum;
        level.push(root);
        while(!level.empty())
        {
            int size=level.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=level.front();
                level.pop();
                sum+=node->val;
                if(node->left){level.push(node->left);}
                if(node->right){level.push(node->right);}
            }
          }
        int index=0;
        int element=Sum[0];
        for(int i=0;i<Sum.size();i++)
        {
            if(element<Sum[i])
            {
                element=Sum[i];
                index=i;
            }
           
        }
      return index+1;
    }
};
