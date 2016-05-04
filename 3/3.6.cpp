/*************************************************************************
	> 文件名: 3.6.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 19时47分25秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<iterator>
#include<algorithm>
using namespace std;

void sort(stack<int>& intStack)
{
    if(intStack.empty() || intStack.size() == 1)
        return;

    stack<int> tmpStack;

    int tmp;
    while(!intStack.empty())
    {
        tmp = intStack.top();
        intStack.pop();
        if(!tmpStack.empty())
        {
            while(!tmpStack.empty() && tmpStack.top() < tmp)
            {
                intStack.push(tmpStack.top());
                tmpStack.pop();
            }
        }
        tmpStack.push(tmp);
    }

    while(!tmpStack.empty())
    {
        intStack.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main()
{
    stack<int> intStack;
    intStack.push(1);
    intStack.push(4);
    intStack.push(7);
    intStack.push(2);
    intStack.push(8);
    intStack.push(9);
    intStack.push(5);
    intStack.push(3);
    intStack.push(6);
    intStack.push(21);

    sort(intStack);
    ostream_iterator<int> out(cout, " ");

    //stack does not have iterator
    while(!intStack.empty())
    {
        out = intStack.top();
        intStack.pop();
    }
}
