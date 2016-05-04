/*************************************************************************
	> 文件名: 9.5.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月26日 星期六 12时56分00秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

vector<list<int>> permutation(const vector<int>& set)
{
    if(set.empty())
        return vector<list<int>>(); // empty set is not define

    //sort and unique the elememts
    vector<int> sortedSet(set);
    sort(sortedSet.begin(), sortedSet.end());
    sortedSet.erase(unique(sortedSet.begin(), sortedSet.end()), sortedSet.end());

    vector<list<int>> result, lastResult;
    list<int> emptySet;
    if(sortedSet.size() == 1)
    {
        list<int> tmpset;
        tmpset.push_back(sortedSet.back());
        result.push_back(tmpset);
        return result;
    }

    //size >= 2
    int lastItem = sortedSet.back();
    sortedSet.pop_back();
    lastResult = permutation(sortedSet);

    for(auto i : lastResult)
    {
        list<int> tmpList(i);
        int size = tmpList.size();  //total list<int> is size+1
        
        for(int s = 0; s < size; s++)
        {
            tmpList = i;
            int count = s;
            auto iter = tmpList.begin();
            while(count > 0)
            {   //前进到正确位置
                iter++;
                count--;
            }
            tmpList.insert(iter, lastItem);

            result.push_back(tmpList);
        }

        //the last list<int> append
        tmpList = i;
        tmpList.push_back(lastItem);
        result.push_back(tmpList);
    }

    return result;
}

void printSet(const list<int>& set)
{
    if(set.empty())
        cout <<endl;

    ostream_iterator<int> out(cout, " ");
    copy(set.cbegin(), set.cend(), out);
    cout<<endl;
}

int main()
{
    vector<int> iVec{2,1,3,4,5,8,7,9};
    //vector<int> iVec{7};
    vector<list<int>> result = permutation(iVec);

    if(result.empty())
    {
        cout<<"no reslut!"<<endl;
        return -1;
    }

    cout<<"has total "<<result.size()<<" permutation\n"<<endl;

    for(int i = 0; i < result.size(); i++)
    {
        printSet(result[i]);
    }
    cout<<endl;

    cout<<"has total "<<result.size()<<" permutation"<<endl;
}
