/*************************************************************************
        > 文件名: 1.5_1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 11时05分31秒
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename outType, typename inType>
outType convert(inType item) {
  stringstream s;
  s << item;
  outType out;
  s >> out;
  return out;
}

int countCompression(const string& str) {
  char last = str[0];
  int count = 1;
  int size = 0;

  for (int i = 1; i < str.size(); i++) {
    if (str[i] == last)
      count++;
    else {
      size += 1 + convert<string>(count).size();
      last = str[i];
      count = 1;
    }
  }

  // the last character
  size += 1 + convert<string>(count).size();

  return size;
}

string compress(const string& str) {
  if (countCompression(str) >= str.size()) return str;

  string tempStr;
  char last = str[0];
  int count = 1;

  for (int i = 1; i < str.size(); i++) {
    if (str[i] == last)
      count++;
    else {
      tempStr += last;
      last = str[i];
      tempStr += convert<string>(count);
      count = 1;
    }
  }

  tempStr += last;
  tempStr += convert<string>(count);

  return tempStr;
}

int main() {
  string str;
  cin >> str;
  cout << compress(str) << endl;
}
