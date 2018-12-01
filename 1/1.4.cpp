/*************************************************************************
        > 文件名: 1.4.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月21日 星期一 22时35分16秒
 ************************************************************************/

#include <cstdio>
#include <cstring>

void replaceSpace(char *str, int length) {
  if (str == nullptr) return;

  char *ptr = str;

  int NumSpace = 0;
  while (*ptr != '\0') {
    if (*ptr == ' ') NumSpace++;
    ptr++;
  }

  int size = strlen(str);

  int end = size + 2 * NumSpace;

  str[end] = '\0';

  if (end > length - 1) return;

  for (int i = size - 1, j = end - 1; i >= 0, j >= 0; i--) {
    if (str[i] != ' ') {
      str[j] = str[i];
      j--;
    } else {
      str[j--] = '0';
      str[j--] = '2';
      str[j--] = '%';
    }
  }
}

int main() {
  char str[100] = {"32  3 24 fef erg rg e dw fde fre fe fe r"};
  replaceSpace(str, sizeof(str));

  printf("%s\n", str);
}
