/*************************************************************************
        > 文件名: 4.1_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 21时55分47秒
 ************************************************************************/

int checkHight(TreeNode *root) {
  if (root == nullptr) return 0;  // the height is zero

  int leftHight = checkHight(root->left);
  if (leftHight == -1) return -1;

  int rightHight = checkHight(root->right);
  if (rightHight == -1) return -1;

  int heightDiff = leftHight - rightHight;

  if (heightDiff > 1 || heightDiff < -1)
    return -1;
  else
    return leftHight > rightHight ? leftHight : rightHight + 1;
}

bool balanceTree(TreeNode *root) {
  if (checkHight(root) == -1)
    return false;
  else
    true;
}
