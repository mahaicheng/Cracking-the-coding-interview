/*************************************************************************
        > 文件名: 7.4.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 11时24分54秒
 ************************************************************************/

#include <iostream>
using namespace std;

namespace mhc {
int negate(int a) {
  int neg = 0;
  int d = a < 0 ? 1 : -1;
  while (a != 0) {
    neg += d;
    a += d;
  }
  return neg;
}

int minus(int a, int b) { return a + negate(b); }
};  // namespace mhc

int main() {
  int a, b;
  cin >> a >> b;
  cout << mhc::minus(a, b) << endl;
}
