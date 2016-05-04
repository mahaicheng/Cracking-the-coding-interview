/*************************************************************************
	> 文件名: 5.7_1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月24日 星期四 20时03分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int findUnexistNumber(const vector<int>& iVec)
{
    if(iVec.size() == 0)
        return -1;

    int n = iVec.size() + 1;

    int sum = accumulate(iVec.cbegin(), iVec.cend(), 0);

    return ((iVec[0]+iVec.back())*n)/2 - sum;
}

int main()
{
    vector<int> iVec{0,1,2,3,4,5,7,8};

    cout << findUnexistNumber(iVec);
}
