/*************************************************************************
	> 文件名: 1.1_2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月21日 星期一 21时04分02秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

bool uniqueChar(string str)
{
    sort(str.begin(), str.end());

    for(int i = 2; i < str.size(); ++i)
    {
        if(str[i] == str[i-1])
            return false;
    }

    return true;
}

int main()
{
    string str;
    cin >> str;

    if(uniqueChar(str))
        cout<<"Unique Char"<<endl;
    else
        cout<<"Not Unique Char"<<endl;
}
