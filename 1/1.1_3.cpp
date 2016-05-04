/*************************************************************************
	> 文件名: 1.1_3.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年02月29日 星期一 20时48分35秒
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool isUniqueChar(const string& str)
{
    if(str.empty())
        return true;

    if(str.size() > 256)
        return false;

    unordered_map<char, int> cache;

    for(auto c : str)
    {
        cache[c]++;
        if(cache[c] > 1)
            return false;
    }
    return true;
}

int main()
{
    bool state = isUniqueChar("abchdakr");

    if(state)
        cout<<"unique char"<<endl;
    else
        cout<<"not unique char"<<endl;
}
