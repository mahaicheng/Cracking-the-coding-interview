/*************************************************************************
	> 文件名: 11.1.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 20时10分08秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

int sortedNum(int *p, int length)
{
    if(p == nullptr)
        return 0;

    if(length == 1)
        return 1;

    for(int i = 1; i < length; i++)
    {
        if(p[i-1] > p[i])
            return i;
    }
}

void merge(int *a, int lastA, const int *b, int lastB)
{
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int indexMerged = lastA + lastB - 1;

    while(indexA >= 0 && indexB >= 0)
    {
        if(a[indexA] < b[indexB])
        {
            a[indexMerged--] = b[indexB--];
        }
        else if(a[indexA] > b[indexB])
        {
            a[indexMerged--] = a[indexA--];
        }
        else
        {   // a[indexA] == b[indexB]
            a[indexMerged--] = a[indexA--];
            a[indexMerged--] = b[indexB--];
        }
    }

    while(indexB >=0)
    {
        a[indexMerged--] = b[indexB--];
    }
}

int main()
{
    int a[25] = {0,2,4,6,7,9};
    int b[10] = {1,2,4,6,8,9,11,14,16,17};

    merge(a, sortedNum(a, sizeof(a)), b, sortedNum(b, sizeof(b)));

    ostream_iterator<int> out(cout, " ");
    copy(begin(a), end(a), out);
    cout<<endl;
}
