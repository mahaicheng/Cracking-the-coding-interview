/*************************************************************************
        > 文件名: 4.7_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月23日 星期三 15时33分18秒
 ************************************************************************/

bool find(Node *root, Node *node) {
  if (root == nullptr) return false;

  if (root == node) return true;

  return find(root->left, node) || find(root->right, node);
}

Node *commonAncestor(Node *root, Node *node1, Node *node2) {
  if (root == nullptr || node1 == nullptr || node2 == nullptr) return nullptr;

  if (find(root->left, node1) && find(root->left, node2))
    return commonAncestor(root->left, node1, node2);
  else if (find(root->right, node1) && find(root->right, node2))
    return commonAncestor(root->right, node1, node2);
  else
    return root;
}
