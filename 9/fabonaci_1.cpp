/*************************************************************************
        > 文件名: fabonaci_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 15时40分43秒
 ************************************************************************/

#include <iostream>
using namespace std;

long fabonaci(int n) {
  if (n <= 0) return 0;

  if (n == 1 || n == 2) return 1;

  return fabonaci(n - 1) + fabonaci(n - 2);
}

int main() {
  int n;
  cin >> n;
  cout << fabonaci(n) << endl;
}
