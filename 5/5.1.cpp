/*************************************************************************
        > 文件名: 9.5.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年12月23日 星期三 17时03分20秒
 ************************************************************************/

// valiable j is on the left, i is on the right
int updateBits(int n, int m, int j, int i) {
  // -> 11111111
  int allOnes = ~0;
  // -> 11110000
  int left = allOnes << (j + 1);
  // 1 << 2    -> 00000100
  //(1 << 2)-1 -> 00000011
  int right = (1 << i) - 1;

  // -> 11110011
  int mask = left | right;

  int n_cleard = n & mask;
  int m_shifted = m << i;

  return n_cleard | m_shifted;
}
