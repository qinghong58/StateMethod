#pragma once
#include<iostream>
#include<memory>
using namespace std;

template<typename T>
class Singleton
{
public:
    static shared_ptr<T>GetInstance()
    {
        static shared_ptr<T>instance = make_shared<T>();
        return instance;
    }

    Singleton(T&&) = delete;
    Singleton(const T&) = delete;
    void operator= (const T&) = delete;

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};