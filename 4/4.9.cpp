/*************************************************************************
        > 文件名: 4.9.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月23日 星期三 16时27分06秒
 ************************************************************************/

#include <algorithm>
#include <numeric>
#include <vector>

int TreeNodeSum(vector<TreeNode*> route) {
  if (route.empty()) return 0;

  int sum = 0;
  for (auto i : route) {
    sum += i->value;
  }

  return sum;
}

void checkSum(TreeNode* root, int num, vector<TreeNode*>& route,
              vector<vector<TreeNode*>>& result) {
  if (root == nullptr) return;

  route.push_back(root);
  if (TreeNodeSum(route) == num) result.push_back(route);
}

vector<vector<TreeNode*>> routeSum(TreeNode* root, int num) {
  if (root == nullptr) return vector<vector<TreeNode*>>();

  vector<vector<TreeNode*>> result;
  vector<TreeNode*> route;
  checkSum(root, num, route, result);
  return result;
}
