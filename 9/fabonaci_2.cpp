/*************************************************************************
	> 文件名: fabonaci_2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 15时45分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


long fabonaciHelper(int n, vector<long>& value)
{
    if(n <= 0)
        return 0;

    if(value.size() >= n)
        return value[n-1];

    value.push_back(fabonaciHelper(n-1, value) + fabonaciHelper(n-2, value));
    return value[n-1];
}

long fabonaci(int n)
{
    vector<long> value{1, 1};
    return fabonaciHelper(n, value);
}

int main()
{
    int n;
    cin >> n;
    cout << fabonaci(n) << endl;
}
