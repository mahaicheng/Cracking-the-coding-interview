/*************************************************************************
        > 文件名: 2.6.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 16时48分53秒
 ************************************************************************/

Node *findBeginning(Node *head) {
  if (head == nullptr) return nullptr;

  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
  }

  if (fast == nullptr || fast->next == nullptr) return nullptr;

  slow = head;
  while (slow != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  return fast;
}
