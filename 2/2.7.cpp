/*************************************************************************
	> 文件名: 2.7.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 17时08分11秒
 ************************************************************************/

Node* reverse(Node *head)
{
    if(head == nullptr)
        return nullptr;

    Node *p1 = head;
    Node *p2 = head->next;
    Node *p3 = nullptr;
    while(p2->next != nullptr)
    {
        p2->next = p1;
        p3 = p2;
        p2
    }
}

bool palindrome(Node *head)
{
    Node *p = reverse(head);
    Node *ptr1 = head, *ptr2 = p;
    while(ptr1 != nullptr)
    {
        if(*ptr1 != *ptr2)
            return false;

        ptr1++;
        ptr2++;
    }
    return true;
}

bool palindrome(Node *head)
{
    if(head == nullptr)
        return false;

    stack<int> intStack;
    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        intStack.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != nullptr)
        slow = slow->next;

    while(slow != nullptr)
    {
        int i = intStack.pop();
        if(i != slow->val)
            return false;
        slow = slow->next;
    }
    return true;
}


