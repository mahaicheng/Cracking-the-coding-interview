/*************************************************************************
        > 文件名: 1.1.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月21日 星期一 20时36分59秒
 ************************************************************************/

#include <bitset>
#include <iostream>

using namespace std;

bool uniqueChar(const string& str) {
  if (str.size() > 256) return false;

  bitset<256> charSet;

  for (auto i : str) {
    if (charSet.test(i)) return false;

    charSet.set(i, true);
  }

  return true;
}

int main() {
  string str;
  cin >> str;

  bool UniqueChar = uniqueChar(str);

  if (UniqueChar)
    cout << "UniqueChar" << endl;
  else
    cout << "Not uniqueChar" << endl;
}
