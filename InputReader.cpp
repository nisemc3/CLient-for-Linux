#include "InputReader.h"
template class InputReader<std::string>;

template<class T>
bool InputReader<T>::checkForSize(const T& inputStr) const
{
	if (inputStr.size() > 64 || inputStr.size() <= 0)
	{
		std::cout << "Incorrect lenght\n";
		return false;
	}
	else return true;
}

template<class T>
void InputReader<T>::changeEven(T& inputStr)
{
	int addSize = 0;
	for (auto& it : inputStr)
	{
		if (!(it & 1) && std::isdigit(it))
		{
			addSize++;
		}
	}
	inputStr.reserve(inputStr.size() + addSize);

	std::string::iterator iterator = m_inputStr.begin();

	for (int pos = 0; iterator < inputStr.end(); pos++)
	{
		if (!(m_inputStr[pos] & 1) && std::isdigit(inputStr[pos]))
		{
			inputStr[pos] = 'K';
			inputStr.insert(iterator + 1, 'B');
		}
		iterator++;
	}
}

template<class T>
bool InputReader<T>::containsOnlyDigits(const T& inputStr) const
{
	bool isDigitLine = true;
	for (const auto& it : inputStr)
	{
		if (!std::isdigit(it))
		{
			std::cout << "Some non digits found\n";
			isDigitLine = false;
			break;
		}
	}
	return isDigitLine;
}

template<class T>
void InputReader<T>::sendDataToBuffer() const
{
	Buffer<std::string>::GetInstance()->setData(m_inputStr);
}

template<class T>
void InputReader<T>::readInput()
{
	std::cout << "Enter line of digits (no more than 64 characters):\n";
	while (1)
	{
		std::getline(std::cin, m_inputStr);
		if (!checkForSize(m_inputStr))
			continue;
		if (!containsOnlyDigits(m_inputStr))
			continue;
		std::sort(m_inputStr.begin(), m_inputStr.end(), std::greater<char>());
		changeEven(m_inputStr);
		sendDataToBuffer();
	};
}