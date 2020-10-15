// count_pairs_test.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	
	// �������� �� ���������� ���������� �������
	if (argc != 5)
	{
		std::cout << "��� ���������� ������ ��������� ���������� 5 ���������." << std::endl << "������: count_pairs.exe ���������_������.txt ������ ������ 5  " << std::endl;
		return(0);
	}
	

	//���������� ����� 
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
	//���� ���� �� ��������
	else
	{
		std::cout << "���� �� ��������, �������� ���� ������ �������." << std::endl;
		return(0);
	}

	//���� ���������� ��� ����� ����, �.� � ������ ������ ����������� ���� ������ ��������� ���������
	// ����� ������� ����� � 'words'
	const auto FirstWord = std::find(words.begin(), words.end(), argv[2]);
	if (FirstWord == words.end())
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	// ����� ������� ����� ����� ������� �'words'.
	const auto SecondWord = std::find(FirstWord, words.end(), argv[3]);
	if (SecondWord == words.end())
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	
	const auto distance = SecondWord - (FirstWord + 1);

	//�������� ���������� ��������� �� �����
	std::stringstream convert(argv[4]);
	int req_distance;
	if (!(convert >> req_distance))
		std::cout << "������������ ������ ��� ����������" << std::endl;

	if (distance == req_distance)
		count = +1;
	
	std::cout << count << std::endl;
	return count;
}

