/*************************************************************************
        > 文件名: 1.1_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月21日 星期一 20时58分48秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool uniqueChar(const string& str) {
  int size = str.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (str[i] == str[j]) return false;
    }
  }

  return true;
}

int main() {
  string str;
  cin >> str;

  if (uniqueChar(str))
    cout << "Unique Char" << endl;
  else
    cout << "Not Unique Char" << endl;
}
