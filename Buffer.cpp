#include "Buffer.h"

template class Buffer<std::string>;


template <class T>
Buffer<T>* Buffer<T>::m_Buffer = nullptr;

template <class T>
std::mutex Buffer<T>::m_mutex;

template <class T>
Buffer<T>* Buffer<T>::GetInstance()
{
    std::lock_guard<std::mutex> ul(m_mutex);
    if (m_Buffer == nullptr)
    {
        m_Buffer = new Buffer<T>();
    }
    return m_Buffer;
}

template <class T>
Buffer<T>::Buffer()
{
    m_observer = nullptr;
}

template <class T>
void Buffer<T>::clear()
{
    std::unique_lock<std::mutex> ul(m_mutex);
    m_data.clear();
    ul.unlock();
    m_observer->setSleep(true);
}

template <class T>
void Buffer<T>::setData(const T& data)
{
    std::unique_lock<std::mutex> ul(m_mutex);
    m_data = data;
    ul.unlock();
    this->notify();
}

template <class T>
void Buffer<T>::attach(IObserver* observer)
{
    m_observer = observer;
}

template <class T>
void Buffer<T>::notify()
{
    if (m_observer != nullptr)
    {
        m_observer->setSleep(false);
        m_observer->getCondition()->notify_one();
    }
}

template <class T>
bool Buffer<T>::isEmpty() const
{
    std::unique_lock<std::mutex> ul(m_mutex);
    return m_data.size();
}

template <class T>
size_t Buffer<T>::size() const
{
    std::unique_lock<std::mutex> ul(m_mutex);
    return m_data.size();
}

template <class T>
T Buffer<T>::getData() const
{
    std::unique_lock<std::mutex> ul(m_mutex);
    return m_data;
}