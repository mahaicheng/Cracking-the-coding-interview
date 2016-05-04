/*************************************************************************
	> 文件名: 2.2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 15时06分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

int kThToLast(Node *head, int k)
{
    if(head == nullptr)
        return 0;

    int i = kThToLast(head->next, k) + 1;
    if(i == k)
        cout<<"the Kth to Last is "<<head->val<<endl;

    return i;
}

Node* kThToLast(Node* head, int k, int& i)
{
    if(head == nullptr)
        return 0;

    Node* nd = kThToLast(head->next, k, i);
    i++;
    if(i == k)
    {
        return head;
    }

    return nd;
}

Node* kThToLast(Node* head, int k)
{
    Node *p1 = head, *p2 = head;

    for(int i = 0; i < k - 1; i++)
    {
        if(p2 == nullptr)
            return nullptr;
        p2 = p2 ->next;
    }

    while(p2->next != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
