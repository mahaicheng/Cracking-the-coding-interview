/*************************************************************************
	> 文件名: 5.2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月24日 星期四 10时30分17秒
 ************************************************************************/

#include<bitset>
#include<iostream>

using namespace std;

bitset<32> convertToBinary(double num)
{
    if(num < 0.0 || num > 1.0)
        return bitset<32>();

    bitset<32> binary;
    for(int i = 0; i < 32; ++i)
    {
        num *= 2.0;

        if(num >= 1.0)
        {
            num -= 1.0;
            binary.set(31-i);
        }
    }

    return binary;
}

int main()
{
    double num;
    cin >> num;
    cout<<"."<<convertToBinary(num)<<endl;
}
