#pragma once
#include <string>
#include <mutex>
#include <condition_variable>

// ����������� �����-�����������, ���������� �������� ����� ���������� ��������� �� ���� ����� 
// (����������� �������� ������ ������ �������, ������� �������� condition_variable).
// ������ ��� ����, ����� ����� ���� ���������� ����� �� ����������.
class IObserver 
{
public:
	virtual ~IObserver() {};
	virtual void setSleep(bool) = 0;
	virtual std::condition_variable* getCondition() = 0;
};

// ����������� �����-��������, ���������� �������� ����� ���������� �����-�����������.
class ISubject 
{
public:
	virtual ~ISubject() {};
	virtual void attach(IObserver* observer) = 0;
	virtual void clear() = 0;

};