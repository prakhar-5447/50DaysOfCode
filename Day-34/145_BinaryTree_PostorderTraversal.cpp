// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insert(TreeNode *root, int val)
{

    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

class Solution
{
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        if (root->left != NULL)
            postorderTraversal(root->left);
        if (root->right != NULL)
            postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

int main()
{
    TreeNode *root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    Solution pst;
    vector<int> v = pst.postorderTraversal(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}