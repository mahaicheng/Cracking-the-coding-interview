/*************************************************************************
	> 文件名: 5.5_1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月24日 星期四 19时29分47秒
 ************************************************************************/

#include<iostream>
using namespace std;


int bitsAToB(int a, int b)
{
    int count = 0;
    for(int c = a ^ b; c > 0; c = c & (c - 1))
    {
        count++;
    }
    
    return count;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bitsAToB(a, b) << endl;
}
