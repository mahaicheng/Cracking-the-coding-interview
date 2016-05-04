/*************************************************************************
	> 文件名: 9.8.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月26日 星期六 17时59分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int makecharge(int n, int denom)
{
    int next_denom = 0;

    switch(denom)
    {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            return 1;
    }

    int ways = 0;
    for(int i = 0; i*denom <= n; i++)
    {
        ways += makecharge(n-i*denom, next_denom);
    }
    return ways;
}

int main()
{
    int n;
    cin >> n;
    cout<<makecharge(n, 25)<<endl;
}
