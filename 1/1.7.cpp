/*************************************************************************
        > 文件名: 1.7.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 13时06分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

void setZero(int **matrix, int rowLength, int columnLength) {
  int row[rowLength] = {0};
  int column[columnLength] = {0};

  for (int i = 0; i < rowLength; i++) {
    for (int j = 0; j < columnLength; j++) {
      if (matrix[i][j] == 0) {
        row[i] = true;
        column[j] = true;
      }
    }
  }

  for (int i = 0; i < rowLength; ++i) {
    for (int j = 0; j < columnLength; j++) {
      if (row[i] || column[j]) matrix[i][j] = 0;
    }
  }
}
