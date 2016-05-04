/*************************************************************************
	> 文件名: 2.1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 14时08分59秒
 ************************************************************************/

#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<unordered_set>
using namespace std;

void deleteDups(list<int>& head)
{
    if(head.size() == 0 || head.size() == 1)
        return;

    unordered_set<int> set;

    for(auto iter = head.begin(); iter != head.end();)
    {
        if(find(set.begin(), set.end(), *iter) != set.end())
            iter = head.erase(iter);
        else
        {
            set.insert(*iter);
            iter++;
        }
    }
}

int main()
{
    list<int> head{1,1,0,3,4,5,6,7,5,8,7,6,5};
    deleteDups(head);
    
    ostream_iterator<int> out(cout, " ");
    copy(head.cbegin(), head.cend(), out);
    cout<<endl;
}
