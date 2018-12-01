/*************************************************************************
        > 文件名: 5.2_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月24日 星期四 11时03分32秒
 ************************************************************************/

#include <bitset>
#include <iostream>
using namespace std;

bitset<32> convertToBinary(double num) {
  if (num >= 1.0 || num < 0.0) return bitset<32>();

  bitset<32> binary;
  double base = 1.0;

  for (int i = 0; i < 32; ++i) {
    if (num >= base) {
      num -= base;  // the base part has been compare, so remove it
      binary.set(31 - i);
    }
    base /= 2.0;
  }

  return binary;
}

int main() {
  double num;
  cin >> num;

  bitset<32> binary = convertToBinary(num);
  cout << boolalpha << "." << binary << endl;
}
