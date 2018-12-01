/*************************************************************************
        > 文件名: 5.6.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月24日 星期四 19时47分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

int exchangeEvenAndOdd(int num) {
  return (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));
}

int main() {
  int num;
  cin >> hex >> num;

  cout << hex << exchangeEvenAndOdd(num) << endl;
}
