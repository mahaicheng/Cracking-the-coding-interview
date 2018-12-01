/*************************************************************************
        > 文件名: 2.3.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 15时30分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

Node* delete (Node* current) {
  if (current == nullptr) return nullptr;

  if (current->next == nullptr) {
    cout << "fault parameter" << endl;
    return nullptr;
  }

  current->val = current->next->val;
  Node* tempNode = current->next;
  current->next = current->next->next;
  delete tempNode;
  tempNode = nullptr;
  return
}
