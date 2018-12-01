/*************************************************************************
        > 文件名: 1.3_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月21日 星期一 21时42分44秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool permutation(const string& str1, const string& str2) {
  if (str1.size() != str2.size()) return false;

  vector<int> set1(256, 0), set2(256, 0);

  for (auto i : str1) {
    set1[i]++;
  }
  for (auto i : str2) {
    set2[i]++;
  }
  if (set1 == set2)
    return true;
  else
    return false;
}

int main() {
  string str1, str2;
  cin >> str1 >> str2;

  if (permutation(str1, str2))
    cout << "permutation" << endl;
  else
    cout << "not permutation" << endl;
}
