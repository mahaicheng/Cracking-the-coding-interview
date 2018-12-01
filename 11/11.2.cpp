/*************************************************************************
        > 文件名: 11.2.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月26日 星期六 20时06分18秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string sortStr(const string& str) {
  if (str.empty()) return string();

  string resultStr(str);
  sort(resultStr.begin(), resultStr.end());
  return resultStr;
}

void sort(vector<string>& vecStr) {
  if (vecStr.empty()) return;

  unordered_map<string, vector<string>> hashStr;

  for (string str : vecStr) {
    string key(sortStr(str));
    /*if(hashStr.find(key) == hashStr.end())
    {
        hashStr.insert(make_pair(key, vector<string>()));
    }*/
    hashStr[key].push_back(str);  // if no vector<string>, build it
  }

  vecStr.clear();  // clean the orignal string data

  for (auto pairStr : hashStr) {
    vector<string> vStr = pairStr.second;
    for (string sStr : vStr) {
      vecStr.push_back(sStr);
    }
  }
}

int main() {
  vector<string> vecStr{"acre", "hi", "race", "ih", "mhc", "hcm", "ma", "care"};

  sort(vecStr);

  for (auto str : vecStr) {
    cout << str << "\n";
  }
}
