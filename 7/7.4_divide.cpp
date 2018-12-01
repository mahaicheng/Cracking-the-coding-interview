/*************************************************************************
        > 文件名: 7.4_divide.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 12时00分06秒
 ************************************************************************/

#include <exception>
#include <iostream>
#include <stdexcept>
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

int divide(int a, int b) {
  if (b == 0) throw logic_error("invalid b");

  // a/b=x means a = bx, so the process need to calculate x by multiply function

  int x = 0;
  int result = 0;
  while (result + x < a) {
    result += b;
    x++;
  }

  if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
    return x;
  } else
    return negate(x);
}

}  // namespace mhc

int main() {
  int a, b;
  cin >> a >> b;
  cout << mhc::divide(a, b) << endl;
}
