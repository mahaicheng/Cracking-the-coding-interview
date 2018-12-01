/*************************************************************************
        > 文件名: 11.5.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月26日 星期六 22时17分35秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int newMid(const vector<string>& strVec, int mid, int start, int end) {
  if (strVec.empty() || mid < 0) return -1;

  int leftDistance = 0;
  int rightDistance = 0;

  while ((mid + rightDistance) <= end && strVec[mid + rightDistance].empty())
    rightDistance++;

  while ((mid - leftDistance) >= start && strVec[mid - leftDistance].empty())
    leftDistance++;

  if (leftDistance < rightDistance)
    return mid - leftDistance;
  else
    return mid + rightDistance;
}

int findHelper(const vector<string>& strVec, int start, int end,
               const string& itemStr) {
  if (strVec.empty() || start > end || itemStr.empty())
    return -1;  // start > end is the terminal condition

  int mid = (start + end) / 2;
  if (strVec[mid] == itemStr)
    return mid;

  else {
    if (!strVec[mid].empty()) {  // normal condition
      if (itemStr < strVec[mid])
        return findHelper(strVec, start, mid - 1, itemStr);
      else
        return findHelper(strVec, mid + 1, end, itemStr);
    } else {  // strVec[mid] is empty
      mid = newMid(strVec, mid, start, end);

      if (strVec[mid] == itemStr) return mid;

      if (itemStr < strVec[mid])
        return findHelper(strVec, start, mid - 1, itemStr);
      else
        return findHelper(strVec, mid + 1, end, itemStr);
    }
  }
}

int find(const vector<string>& strVec, const string& itemStr) {
  if (strVec.empty() || itemStr.empty()) return -1;

  return findHelper(strVec, 0, strVec.size() - 1, itemStr);
}

int main() {
  vector<string> strVec{"a", "b", "",  "c", "", "e", "",
                        "",  "",  "f", "",  "", "g"};
  int position = find(strVec, "");

  if (position < 0)
    cout << "input error or not found" << endl;
  else
    cout << "position: " << position << endl;
}
