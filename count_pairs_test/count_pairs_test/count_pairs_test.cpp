// count_pairs_test.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream> 
#include <algorithm>   
#include <list>
#include <Windows.h>
#include <locale>


int main(int argc, char **argv)
{
	
	int count = 0;
	std::string word;
	std::vector<std::string> words;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	// Проверка на количество аргументов команды
	if (argc != 5)
	{
		std::cout << "Для корректной работы программы необходимо 5 элементов." << std::endl <<  "Пример: count_pairs.exe Налоговый_кодекс.txt налоги России 5"   << std::endl;
		return(0);
	}
	

	//Открывание файла  
	std::ifstream myfile;
	myfile.open(argv[1]);

	if (myfile.is_open())
	{	
		while (myfile >> word)
		{			
			//std::cout << word << std::endl;
			words.push_back(word);
		}
		myfile.close();

	}
	//Если файл не открылся
	else
	{
		std::cout <<  "Файл не открылся, возможно путь указан неверно." << std::endl;
		return(0);
	}

	//Надо переделать это через цикл, т.к в данный момент проверяется лишь первая найденная дистанция
	// Поиск Первого слова в 'words'
	const auto FirstWord = std::find(words.begin(), words.end(), argv[2]);
	if (FirstWord == words.end())
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	// Поиск Второго слова после Первого в'words'.
	const auto SecondWord = std::find(FirstWord, words.end(), argv[3]);
	if (SecondWord == words.end())
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	
	const auto distance = SecondWord - (FirstWord + 1);

	///Проверка последнего аргумента на число
	std::stringstream convert(argv[4]);
	int req_distance;
	if (!(convert >> req_distance))
		std::cout << "Неправильный формат для расстояния" << std::endl;

	if (distance == req_distance)
		count = +1;
	
	std::cout << count << std::endl;
	return count;
}

