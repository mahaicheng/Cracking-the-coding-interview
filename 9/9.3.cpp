/*************************************************************************
	> 文件名: 9.3.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 17时07分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

namespace mhc
{
    // O(n)
    //return value is the position on iVec
    int magicSlow(const vector<int>& iVec)
    {
        if(iVec.size() == 0)
            return -1;  // -1 means unfound

        for(int i = 0; i < iVec.size(); i++)
        {
            if(iVec[i] == i)
                return i;
        }

        return -1;
    }
}

int main()
{
    vector<int> iVec{-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};

    int result = mhc::magicSlow(iVec);

    if(result == -1)
        cout<<"unfound"<<endl;
    else
        cout << "found at: "<<result<<endl;
}
