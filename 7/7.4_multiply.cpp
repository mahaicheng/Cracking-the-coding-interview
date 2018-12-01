/*************************************************************************
        > 文件名: 7.4_multiply.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 11时45分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

namespace mhc {
int negate(int);
int abs(int a) {
  if (a < 0) return negate(a);

  return a;
}

int negate(int num) {
  int neg = 0;
  int d = num < 0 ? 1 : -1;

  while (num != 0) {
    neg += d;
    num += d;
  }
  return neg;
}

int multiply(int a, int b) {
  if (a < b) return multiply(b, a);

  // assert a > b later
  int sum = 0;
  for (int i = abs(b); i > 0; i--) {
    sum += a;
  }

  if (b < 0) sum = negate(a);

  return sum;
}
}  // namespace mhc

int main() {
  int a, b;
  cin >> a >> b;
  cout << mhc::multiply(a, b) << endl;
}
