/*************************************************************************
        > 文件名: 4.1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 21时28分00秒
 ************************************************************************/
class TreeNode;
int treeHight(TreeNode* root) {
  if (root == nullptr) return 0;

  int leftHight = treeHight(root->left);
  int rightHight = treeHight(root->right);

  if (leftHight < rightHight)
    return 1 + rightHight;
  else
    return 1 + leftHight;
}

bool balanceTree(TreeNode* root) {
  if (root == nullptr) return true;

  int leftHight = treeHight(root->left);
  int rightHight = treeHight(root->right);

  if (leftHight > rightHight + 1 || rightHight > leftHight + 1)
    return false;
  else
    return balanceTree(root->left) && balanceTree(root->right);
}
