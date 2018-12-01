/*************************************************************************
        > 文件名: 4.5.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 22时42分59秒
 ************************************************************************/

bool binaryTree(TreeNode *root, int min, int max) {
  if (root == nullptr) return true;  // null tree is balance

  if (root->value >= min && root->value < max)
    return binaryTree(root->left, min, root->value) &&
           binaryTree(root->right, root->value, max);

  return false;
}

bool binaryTree(TreeNode *root) {
  if (root == nullptr) return true;

  vector<int> iVec;
  middleSearch(root, iVec);

  if (iVec.size() == 1) {
    return true;
  } else {
    for (int i = 1; i < iVec.size(); i++) {
      if (iVec[i] < iVec[i - 1]) return false;
    }
    return true;
  }
}

void middleSearch(TreeNode *root, vector<int> &iVec) {
  if (root == nullptr) return;  // terminal condition

  middleSearch(root->left, iVec);
  iVec.push_back(root->value, iVec);
  middleSearch(root->right, iVec);
}
