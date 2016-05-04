/*************************************************************************
	> 文件名: 9.4.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月25日 星期五 21时23分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;


vector<vector<int>> subSet(const vector<int>& set)
{
    vector<int> sortedSet(set);
    sort(sortedSet.begin(), sortedSet.end());
    // the element of a set is unique, so need to remove the duplicated element
    sortedSet.erase(unique(sortedSet.begin(), sortedSet.end()), sortedSet.end());
    vector<int> emptySet;
    vector<vector<int>> setOfSet;   // the result
    vector<vector<int>> lastSetOfSet; // last sequeue result

    if(set.empty()) // n == 0
    {
        setOfSet.push_back(emptySet);
        return setOfSet;
    }

    // n >= 1
    int lastInt = sortedSet.back();
    sortedSet.pop_back();
    lastSetOfSet = subSet(sortedSet);   // calculate the lastSetOfSet
    copy(lastSetOfSet.cbegin(), lastSetOfSet.cend(), back_inserter(setOfSet));

    for(auto iter = lastSetOfSet.begin(); iter != lastSetOfSet.end(); ++iter)
    {   //for every vector set ,append a new element lastInt
        iter->push_back(lastInt);
    }

    //copy the new set to the result set of set
    copy(lastSetOfSet.cbegin(), lastSetOfSet.cend(), back_inserter(setOfSet));

    return setOfSet;
}

void printSet(const vector<int>& iVec)
{
    if(iVec.empty())
    {
        cout<<"{}"<<endl;
        return;
    }

    cout<<"{ ";
    ostream_iterator<int> out(cout, " ");
    copy(iVec.cbegin(), iVec.cend(), out);
    cout<<"}"<<endl;
}

int main()
{
    vector<int> iVec{4,5,8,1,3, 4,7,1,2,6,8,9,0,4,3, 32,321,55,97,325};

    vector<vector<int>> setOfSet = subSet(iVec);

    cout<<"has "<<setOfSet.size()<<" subSets"<<endl;

    for(auto i : setOfSet)
    {
        printSet(i);
    }
    cout<<endl;

    cout<<"has "<<setOfSet.size()<<" subSets"<<endl;
}
