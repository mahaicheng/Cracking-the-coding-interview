/*************************************************************************
        > 文件名: 9.1_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 15时29分52秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

long countWays(long n, vector<long>& lVec) {
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else {
    if (lVec.size() >= n)
      return lVec[n - 1];
    else {
      long tmp = countWays(n - 1, lVec) + countWays(n - 2, lVec) +
                 countWays(n - 3, lVec);
      lVec.push_back(tmp);
      return lVec[n - 1];
    }
  }
}

long ways(long n) {
  vector<long> lVec;
  return countWays(n, lVec);
}

int main() {
  int n;
  cin >> n;
  cout << ways(n) << endl;
}
