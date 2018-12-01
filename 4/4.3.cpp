/*************************************************************************
        > 文件名: 4.3.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月22日 星期二 22时35分37秒
 ************************************************************************/

Node* makeTree(int* array, int begin, int end) {
  if (array == nullptr) return nullptr;

  if (end > begin) return nullptr;

  // final condition
  if (begin == end) return new Node(array[begin], nullptr, nullptr);

  int mid = (begin + end) / 2;
  return new Node(array[mid], makeTree(array, begin, mid - 1),
                  makeTree(array, mid + 1, end));
}
