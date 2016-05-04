/*************************************************************************
	> 文件名: 5.4.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月24日 星期四 11时40分51秒
 ************************************************************************/

#include<iostream>
using namespace std;


bool squareOfTwo(int num)
{
    return (num & (num - 1)) == 0;
}

int main()
{
    int num;
    cin >> num;
    cout << boolalpha << squareOfTwo(num) << endl;
}
