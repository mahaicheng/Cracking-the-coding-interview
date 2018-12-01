/*************************************************************************
        > 文件名: 9.2.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月25日 星期五 16时13分47秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

long countHelper(int x, int y, unordered_map<pair<int, int>, long>& cache) {
  if (x < 0 || y < 0) return 0;

  if (cache.find(make_pair(x, y)) != cache.end()) return cache[make_pair(x, y)];

  cache[pair<int, int>(x, y)] =
      countHelper(x - 1, y, cache) + countHelper(x, y - 1, cache);
  return cache[pair<int, int>(x, y)];
}

long count(int x, int y) {
  if (x < 0 || y < 0) return 0;

  unordered_map<pair<int, int>, long> cache;
  //初始情况
  cache.insert(pair<pair<int, int>, long>(pair<int, int>(0, 0), 0));
  cache.insert(pair<int, int>(0, 1), 1);
  cache.insert(pair<int, int>(1, 0), 1);

  return countHelper(x, y, cache);
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << count(x, y) << endl;
}
