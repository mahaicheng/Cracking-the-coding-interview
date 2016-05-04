/*************************************************************************
	> 文件名: 4.7.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月23日 星期三 11时26分40秒
 ************************************************************************/


//not neccesary a binary serach tree
TreeNode* commonAncestor(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr || root2 == nullptr)
        return nullptr;

    vector<TreeNode*> vec1, vec2;

    traceToParent(root1, vec1);
    traceToParent(root2, vec2);

    auto iter = vec1.crbegin();

    for(auto iter1 = vec1.crbegin(), iter2 = vec2.crbegin(); iter1 != vec1.crend(), \
        iter2 != vec2.crend(); iter1++, iter2++)
    {
        if(iter1 != iter2)
        {
            if(iter1 != vec1.crbegin())
            {
                return nullptr;
            }
            else
            {
                iter = --iter1;
            }
        }
    }

    return iter;
}

void traceToParent(TreeNode *root, vector<TreeNode*>& vec)
{
    if(root == nullptr)
        return;

    TreeNode *parent = root->parent;

    while(parent != nullptr)
    {
        vec.push_back(parent);
        parent = parent->parent;
    }
}

//special condition: binary search tree

TreeNode* commonAncestor( TreeNode *root, TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr || root2 == nullptr || root == nullptr)
        return nullptr;

    int min, max, value1, value2;
    value1 = root1->value;
    value2 = root2->value;
    if(value1 < value2)
    {
        min = value1;
        max = value2;
    }
    else
    {
        min = value2;
        max = value1;
    }

    if(root->value >= min && root->value < max)
        return root;
    else
    {
        if(max <= root->value)
            return commonAncestor(root->left, root1, root2);
        else
            return commonAncestor(root->right, root1, root2);
    }
}
