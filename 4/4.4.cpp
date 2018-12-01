/*************************************************************************
        > 文件名: 4.4.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月23日 星期三 14时46分46秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

vector<list<TreeNode *>> createLevelList(TreeNode *root) {
  if (root == nullptr) return vector<list<TreeNode *>>();  // empty container

  vector<list<TreeNode *>> vecList;

  travel(root, 0, vecList);

  return vecList;
}

void travel(TreeNode *root, int level, vector<list<TreeNode *>> &vecList) {
  if (root == nullptr || level < 0) return;

  while (vecList.size() < level + 1) {
    vecList.push_back(list<TreeNode *>());
  }

  vecList[level].push_back(root);
  travel(root->left, level + 1, vecList);
  travel(root->right, level + 1, vecList);
}
