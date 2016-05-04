/*************************************************************************
	> 文件名: 1.3.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月21日 星期一 21时34分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool permution(const string& str1, const string& str2)
{
    if(str1.size() != str2.size())
        return false;

    string tempStr1(str1);
    sort(tempStr1.begin(), tempStr1.end());
    
    string tempStr2(str2);
    sort(tempStr2.begin(), tempStr2.end());

    return tempStr1 == tempStr2;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    if(permution(str1, str2))
        cout<<"permution"<<endl;
    else
        cout<<"not permution"<<endl;
}
