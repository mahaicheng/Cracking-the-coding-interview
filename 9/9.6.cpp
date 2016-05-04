/*************************************************************************
	> 文件名: 9.6.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月26日 星期六 16时53分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

void addParen(vector<string>& vecStr, int leftRemain, int rightRemain, string& str, int count)
{
    if(leftRemain < 0 || rightRemain < leftRemain)
        return;

    if(leftRemain == 0 && rightRemain == 0)
    {
        vecStr.push_back(str);
    }
    else
    {
        if(leftRemain > 0)
        {
            str[count] = '(';
            addParen(vecStr, leftRemain-1, rightRemain, str, count+1);
        }

        if(rightRemain > leftRemain)
        {
            str[count] = ')';
            addParen(vecStr, leftRemain, rightRemain-1, str, count+1);
        }
    }
}

vector<string> generateParens(int count)
{
    vector<string> vecStr;
    string str;
    addParen(vecStr, count, count, str, 0);
    return vecStr;
}

int main()
{
    vector<string> vecStr = generateParens(1);

    if(vecStr.empty())
    {
        cout<<"the result is empty"<<endl;
        return -1;
    }

    ostream_iterator<string> out(cout, "\n");
    copy(vecStr.begin(), vecStr.end(), out);
    cout<<endl;
}
