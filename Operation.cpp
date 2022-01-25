#include "Operation.h"
template class Operation<std::string>;

template <class T>
void Operation<T>::setSleep(bool status)
{
    m_sleep = status;
}

template <class T>
std::condition_variable* Operation<T>::getCondition()
{
    return &m_condition;
}

template <class T>
Operation<T>::Operation(ISubject* subject) : m_buffer(subject)
{

    m_client = new TCPClient();
    this->m_buffer->attach(this);
}

template <class T>
void Operation<T>::operate()
{
    while (1)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_sleep)
        {
            m_condition.wait(lock);
        }
        if (!m_sleep)
        {
            if (Buffer<T>::GetInstance()->size())
            {
                int tempSumm = 0;
                std::string tempStr = Buffer<T>::GetInstance()->getData();
                m_buffer->clear();
                std::cout << tempStr << '\n';
                for (const auto& it : tempStr)
                {
                    if (std::isdigit(it))
                    {
                        tempSumm += it % 48;
                    }
                }
                if (m_client->tryConnect())
                    m_client->sendData(tempSumm);
            }
        }
    }
}
