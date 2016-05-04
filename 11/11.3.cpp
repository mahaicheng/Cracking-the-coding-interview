/*************************************************************************
	> 文件名: 11.3.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月26日 星期六 21时03分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int findHelper(int *array, int start, int end, int item)
{
    if(start > end)
        return -1;

    int mid = (start+end) / 2;
    if(array[mid] == item)
        return mid;

    if(array[start] <= array[mid])
    {
        if(item >= array[start] && item < array[mid])
            return findHelper(array, start, mid-1, item);
        else
            return findHelper(array, mid+1, end, item);
    }
    else
    {   // array[mid] < array[start]
        if(item > array[mid] && item <= array[end])
            return findHelper(array, mid+1, end, item);
        else
            return findHelper(array, start, mid-1, item);
    }
}

int find(int array[], int size, int item)
{
    if(array == nullptr || size <= 0)
        return -1;

    return findHelper(array, 0, size-1, item);
}

int main()
{
    int array[] = {6,7,8,9,0,1,2,3,4};

    int position = find(array, sizeof(array)/sizeof(int), 2);

    if(position < 0)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"position: "<<position<<endl;
    }
}
