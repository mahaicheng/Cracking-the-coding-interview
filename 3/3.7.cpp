/*************************************************************************
	> 文件名: 3.7.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 20时55分57秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<string>

class Cat
{
public:
    string name;
    static int CatNumber;
};

class Dog
{
public:
    string name;
    static int DogNumber;
};

int Cat::CatNumber = 0;
int Dog::DogNumber = 0;

class Zoo
{
public:
    void enqueueCat(Cat animal)
    {
     ;
    }
private:
    queue<Cat> catQueue;
    queue<Dog> dogQueue;
    static int animalNumber;
};

int Zoo::animalNumber = 0;
