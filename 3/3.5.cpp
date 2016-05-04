/*************************************************************************
	> 文件名: 3.5.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 18时49分37秒
 ************************************************************************/

namespace mhc
{
class myQueue
{
public:
    void push(int val)
    {
        stackIn.push(val);
    }
    int pop()
    {
        if(!stackOut.empty())
        {
            int tmp = stackOut.top();
            stackOut.pop();
            return tmp;
        }
        else
        {
            while(!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
            
            int tmp = stackOut.top();
            stackOut.pop();
            return tmp;
        }
    }
private:
    stack<int> stackIn;
    stack<int> stackOut;
};
};
