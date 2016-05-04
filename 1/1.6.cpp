/*************************************************************************
	> 文件名: 1.6.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 11时59分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

void rotate(int **matrix, int n)
{
    for(int layer = 0; layer < n / 2; ++layer)
    {
        int first = layer;
        int last = n - 1 - layer;
        for(int i = first; i < last; i++)
        {
            int offset = i - first;
            //store top
            //int top = matrix[first][i];
            int top = *(*(matrix+first*n)+i);
            //move left to top
            matrix[first][i] = matrix[last-offset][first];
            //move bottom to left
            matrix[last-offset][first] = matrix[last][last-offset];
            //move right to bottom
            matrix[last][last-offset] = matrix[i][last];
            //move top to right
            matrix[i][last] = top;
        }
    }
}

int main()
{
    int matrix[2][2] = {{1,2}, {3,4}};

    rotate((int**)matrix, 2);

    for(int i = 0; i < 4; ++i)
    {
        cout<<*(matrix+i)<<" ";
    }
    cout<<endl;
}
