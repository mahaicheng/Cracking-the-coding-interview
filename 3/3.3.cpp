/*************************************************************************
        > 文件名: 3.3.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 18时15分29秒
 ************************************************************************/

namespace mhc {
class setOfStack {
 public:
  void push(int val) {
    if (stackVec.back().size() < 10) {
      stackVec.back().push_back(val);
    } else {
      stackVec.push_back(vector<int>());
      stackVec.back().push_back(val);
    }
  }
  int pop() {
    int tmp = stackVec.back().back();
    stackVec.back().pop_back();
    if (stackVec.back().size() == 0) {
      stackVec.pop_back();
    }
    return tmp;
  }
  int topAt(int index) const { return stackVec[index - 1].back(); }
  void pushAt(int val, int index) {
    if (stackVec[index - 1].size() > 10) return;

    stackVec[index - 1].push_back(val);
  }
  int popAt(int index) {
    if (index - 1 > stackVec.size()) return -1;

    int tmp = stackVec[index - 1].back();
    stackVec[index - 1].pop_back();
    if (stackVec[index - 1].size() == 0) stackVec.erase(index - 1);
  }

 private:
  vector<vector<int>> stackVec;
  const static int maxSize = 10;
};
};  // namespace mhc
