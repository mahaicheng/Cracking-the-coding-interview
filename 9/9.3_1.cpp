/*************************************************************************
	> 文件名: 9.3_1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 17时20分32秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

namespace mhc
{
    int magicHelper(const vector<int>& iVec, int start, int end)
    {
        if(start > end || iVec.size() == 0)
            return -1;

        int mid = (start + end) / 2;

        while(start <= end)
        {
            if(iVec[mid] == mid)
                return mid;

            if(iVec[mid] > mid)
                end = mid - 1;
            else
                start = mid + 1;

            mid = (start + end) / 2;
        }

        return -1;
    }

    int magic(const vector<int>& iVec)
    {
        if(iVec.size() == 0)
            return -1;

        return magicHelper(iVec, 0, iVec.size()-1);
    }
}

int magicHelper(const vector<int>& iVec, int start, int end)
{
    if(start > end || iVec.size() == 0)
        return -1;

    int mid = (start + end) / 2;

    if(iVec[mid] == mid)
        return mid;
    
    if(iVec[mid] < mid)
        return magicHelper(iVec, mid+1, end);
    else
        return magicHelper(iVec, start, mid-1);
}

int magic(const vector<int>& iVec)
{
    if(iVec.size() == 0)
        return -1;

    return magicHelper(iVec, 0, iVec.size()-1);
}

int main()
{
    vector<int> iVec{-40,-20,-1,1,2,3,5,7,9,12,13};

    int result = mhc::magic(iVec);

    if(result == -1)
        cout<<"unfound"<<endl;
    else
        cout<<"found at: "<<result<<endl;
}
