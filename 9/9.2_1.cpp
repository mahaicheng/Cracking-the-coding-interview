/*************************************************************************
	> 文件名: 9.2_1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 16时41分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

//递归
long count(int x, int y)
{
    if(x < 0 || y < 0)
        return 0;

    if(x == 0 && y == 0)
        return 0;
    if((x == 1 && y == 0) || (x == 0 && y == 1))
        return 1;

    return count(x-1,y) + count(x, y-1);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << count(x, y);
}
