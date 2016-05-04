/*************************************************************************
	> 文件名: 4.6.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月23日 星期三 10时49分30秒
 ************************************************************************/

TreeNode* nextNode(TreeNode *root)
{
    if(root == nullptr)
        return nullptr;

    if(root->right != nullptr)
    {   //has right child, return the min of the right subTree
        TreeNode *ptr = root->right;
        while(ptr->left != nullptr)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
    else
    {   //the right child is empty
        TreeNode *ptr = root->parent;

        if(root == ptr->left)
        {   //root is the left child of parent
            return ptr;     //the parent has not been visited
        }
        else
        {   //root is the right child of parent, so the parent has been visited
            TreeNode *child = root;
            TreeNode *parent = root->parent;
            while(parent != nullptr && parent->right == child)
         {
             child = parent;
             parent = parent->parent;
         }
         if(parent == nullptr)
            return  nullptr;

         return parent;
        }
    }
}
