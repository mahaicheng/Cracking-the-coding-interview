/*************************************************************************
	> 文件名: 1.5.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 10时14分17秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

template<typename T>
string toString(T item)
{
    stringstream s;
    s << item;
    return s.str();
}

//put inType later, let auto deduction happen
template<typename outTpye, typename inType>
outTpye convert(inType item)
{
    stringstream s;
    s << item;
    outTpye out;
    s >> out;
    return out;
}

string compress(const string& str)
{
    string tempStr;
    int count = 1;
    char last = str[0];

    for(int i = 1; i < str.size(); i++)
    {
        if(str[i] == last)
            count++;
        else
        {
            tempStr += last;
            last = str[i];
            //tempStr += toString(count);
            tempStr += convert<string>(count);
            count = 1;
        }
    }

    //the last character could not record inner the circle
    tempStr += last;
    tempStr += toString(count);

    if(tempStr.size() >= str.size())
        return str;     //if enter this situation, the process before is useless. It can be youhua
    else
        return tempStr;
}

int main()
{
    string str;
    cin >> str;
    cout<<compress(str)<<endl;
}
