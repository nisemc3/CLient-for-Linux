﻿/* Описание задания 
* Поток 1.  
* Принимает строку, которую введет пользователь. Должна быть проверка, что строка состоит только из цифр и не превышает 64 символа. 
* После проверки строка должна быть отсортирована по убыванию и все элементы, значение которых чётно, заменены на латинские буквы «КВ». 
* После данная строка помещается в общий буфер и поток должен ожидать дальнейшего ввода пользователя.
* Поток 2. 
* Должен обрабатывать данные которые помещаются в общий буфер. После получения данных общий буфер затирается. 
* Поток должен вывести полученные данные на экран, рассчитать  общую  сумму всех  элементов , которые являются численными значениями.  
* Полученную сумму передать в Программу №2. После этого поток ожидает следующие данные.
* Примечание №1 по Программе №1: Взаимодействие потоков должно быть синхронизировано,  поток №2  не должен постоянно опрашивать общий буфер. 
* Механизм синхронизации не должен быть глобальной переменной.
*/

#include "Main.h"

int main()
{
	// Общий буфер реализован по принципу singleton, вызываем буфер в главном потоке.
	Buffer<std::string>::GetInstance();	
	// Создаем первый поток и инициализируем в нем объект, который осуществляет все действия по заданию.
	std::thread thread1([]()
		{
			//Инициализируем объект, который далее будет обрабатывать пользовательский ввод
			InputReader<std::string> inputRead;
			//Вызываем обрабочик пользовательского ввода (бесконечный цикт)
			inputRead.readInput();
		});
	// Создаем второй поток и инициализируем в нем объект, который осуществляет все действия по заданию.
	std::thread thread2([]() 
		{
			//Инициализируем объект, который далее будет обрабатывать общий буфер
			Operation<std::string> operations ((Buffer<std::string>::GetInstance()));
			//Вызываем обработчик буфера (бесконечный цикл)
			operations.operate(); 
		});
	// Присоединяем потоки обратно
	thread1.join();
	thread2.join();

	return 0;
}