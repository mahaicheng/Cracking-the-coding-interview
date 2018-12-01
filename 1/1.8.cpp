/*************************************************************************
        > 文件名: 1.8.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 13时26分43秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool subString(const string& str, const string& subStr) {
  if (str.size() < subStr.size()) return false;

  for (int i = 0; i < str.size() - subStr.size(); i++) {
    if (str.substr(i, subStr.size()) == subStr) return true;
  }

  return false;
}

bool rotation(const string& str1, const string& str2) {
  if (str1.size() != str2.size()) return false;

  string tempStr(str1);
  tempStr += str1;
  return subString(tempStr, str2);
}

int main() {
  string str1, str2;
  cin >> str1 >> str2;

  if (rotation(str1, str2))
    cout << "rotation" << endl;
  else
    cout << "not rotation" << endl;
}
