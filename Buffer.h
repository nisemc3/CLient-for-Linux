#pragma once
#include "IO.h"
#include <iostream>
#include <vector>
#include <thread>

template <class T>
class Buffer: public ISubject
{
private:
    static Buffer* m_Buffer;
    IObserver* m_observer;
    Buffer();
    Buffer(Buffer& other) = delete;
    void operator=(const Buffer&) = delete;
    T m_data{};
    static std::mutex m_mutex;

public:
    static Buffer<T>* GetInstance();
    void attach(IObserver* observer) override;
    void notify();
    bool isEmpty() const;
    size_t size() const;
    void setData(const T& value);
    void clear() override;
    T getData() const;

};
