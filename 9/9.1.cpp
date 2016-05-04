/*************************************************************************
	> 文件名: 9.1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 15时18分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int countWays(int n)
{
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;   //begining condition
    else
        return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

int main()
{
    int n;
    cin >> n;
    cout<< countWays(n)<<endl;
}
