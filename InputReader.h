#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <algorithm>
#include "Buffer.h"

template <class T>
class InputReader
{
private:
	bool checkForSize(const T&) const;
	bool containsOnlyDigits(const T&) const;
	void changeEven(T&);
	void sendDataToBuffer() const;
	T m_inputStr{};

public:
	void readInput();
};


