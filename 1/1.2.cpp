/*************************************************************************
	> 文件名: 1.2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月21日 星期一 21时09分11秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<string>
using namespace std;


void reverse(char *str)
{
    if(str == nullptr)
        return;

    int length = strlen(str);

    int start = 0;
    int end = length - 1;

    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    string str;
    cin >> str;

    reverse(const_cast<char*>(str.c_str()));

    cout<<str<<endl;
}
