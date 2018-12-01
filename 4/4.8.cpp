/*************************************************************************
        > 文件名: 4.8.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月23日 星期三 16时02分03秒
 ************************************************************************/

bool theSame(Node *root1, Node *root2) {
  if (root1 == nullptr && root2 == nullptr)
    return true;  // if all is empty, so is the same
  else if (root1 == nullptr || root2 == nullptr)
    return false;

  if (root1->value == root2->value) {
    return theSame(root1->left, root2->left) &&
           theSame(root1->right, root2->right);
  }
  return false;
}

bool theSubTree(Node *root, Node *subRoot) {
  if (root == nullptr || subRoot == nullptr) return false;

  return theSame(root, subRoot);
}
