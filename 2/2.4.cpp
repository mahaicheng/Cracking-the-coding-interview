/*************************************************************************
	> 文件名: 2.4.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 15时55分42秒
 ************************************************************************/

Node* listAdd(Node *lhs, Node *rhs, int carry)
{
    if(lhs == nullptr && rhs == nullptr && carry == 0)
        return nullptr;

    Node *result = new Node();

    int value = carry;
    if(lhs != nullptr)
    {
        value += lhs->val;
    }
    if(rhs != nullptr)
    {
        value += rhs->val;
    }

    result->val = value % 10;

    Node *next = listAdd(   lhs == nullptr ? nullptr : lhs->next, \
                         rhs == nullptr ? nullptr : rhs->next, \
                         value >= 10 ? 1 : 0);

    result->next = next;
    return result;
}
