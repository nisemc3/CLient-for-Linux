#pragma once
#include "Buffer.h"
#include "TCPconnection.h"
#include <ctype.h>
#include <stdlib.h>

template <class T>
class Operation : public IObserver 
{
    private:
        ISubject* m_buffer;     // нАЗЪБКЪЕЛ ЙКЮЯЯ-ХГДЮРЕКЭ, ЙНРНПШИ ДЮКЕЕ АСДЕР ОПНАСФДЮРЭ ОНРНЙ ЩРНЦН ЙКЮЯЯЮ
        TCPClient* m_client;
        std::condition_variable m_condition; // гЮУБЮРШБЮЕР Б ЯБНИ ЯОХЯНЙ ОНРНЙ, ЙНРНПШИ АСДЕР НАЗЪБКЕМ ЙЮЙ ЯОЪЫХИ
        std::mutex m_mutex;
        bool m_sleep = false;

    public:
        Operation(ISubject* subject);
        void operate();
        void setSleep(bool) override;
        std::condition_variable* getCondition() override;
};
