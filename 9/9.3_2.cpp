/*************************************************************************
        > 文件名: 9.3_2.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 17时57分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

namespace mhc {
inline int min(int x, int y) { return x <= y ? x : y; }

inline int max(int x, int y) { return x <= y ? y : x; }

int magicHelper(const vector<int>& iVec, int start, int end) {
  if (iVec.size() == 0 || start > end) return -1;

  int midIndex = (start + end) / 2;
  int midValue = iVec[midIndex];
  if (midValue == midIndex) return midIndex;

  int leftIndex = min(midIndex - 1, midValue);

  if (magicHelper(iVec, start, leftIndex) < 0)  //优先搜索左半部分
  {
    int rightIndex = max(midIndex + 1, midValue);
    return magicHelper(iVec, rightIndex, end);
  }

  return magicHelper(iVec, start, leftIndex);
}

int magic(const vector<int>& iVec) {
  if (iVec.size() == 0) return -1;

  return magicHelper(iVec, 0, iVec.size() - 1);
}
}  // namespace mhc

int main() {
  vector<int> iVec{-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
  int result = mhc::magic(iVec);

  if (result < 0)
    cout << "unfound" << endl;
  else
    cout << "found at: " << result << endl;
}
