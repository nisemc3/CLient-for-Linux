#pragma once
#include <string>
#include <mutex>
#include <condition_variable>

// Виртуальный класс-наблюдатель, наследники которого могут передавать указатель на свой поток 
// (посредством передачи списка спящих потоков, которые захватит condition_variable).
// Создан для того, чтобы можно было пробуждать поток по требованию.
class IObserver 
{
public:
	virtual ~IObserver() {};
	virtual void setSleep(bool) = 0;
	virtual std::condition_variable* getCondition() = 0;
};

// Виртуальный класс-издатель, наследники которого могут пробуждать класс-наблюдатель.
class ISubject 
{
public:
	virtual ~ISubject() {};
	virtual void attach(IObserver* observer) = 0;
	virtual void clear() = 0;

};