/*************************************************************************
        > 文件名: 5.5.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月24日 星期四 11时46分50秒
 ************************************************************************/

#include <iostream>
using namespace std;

int bits_from_a_to_b(int a, int b) {
  int count = 0;

  for (int i = a ^ b; i > 0; i = i >> 1) {
    count += i & 1;
  }

  return count;
}

int main() {
  int a, b;
  cin >> a >> b;

  cout << bits_from_a_to_b(a, b) << endl;
}
