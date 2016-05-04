/*************************************************************************
	> 文件名: 3.2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 17时50分46秒
 ************************************************************************/
namespace mhc
{
class stack
{
public:
    void push(int val)
    {
        buffer.push_back(val);
        if(minBuffer.size() == 0)
            minBuffer.push_back(val);
        else
        {   //not empty
            if(val < minBuffer.back())
                minBuffer.push_back(val);
            else
                minBuffer.push_back(minBuffer.back());
        }
    }
    int pop()
    {
        int result = buffer.back();
        buffer.pop_back();
        minBuffer.pop_back();
        return result;
    }
    int min() const
    {
        return minBuffer.back();
    }
    int top() const 
    {
        return buffer.back();
    }
    int size() const
    {
        return buffer.size();
    }
private:
    vector<int> buffer;
    vector<int> minBuffer;
};
};
