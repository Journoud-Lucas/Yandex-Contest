/*
Author: JOURNOUD Lucas
Date: 2025-02-21
Website: Yandex Contest
Problems: Стажировка осень-зима 2024 | бэкенд | D. Правильная последовательность
*/

#include <iostream>
#include <vector>
#include <unordered_map>

/* 
Exemple 1:
4
[]()
Expected output: 1

Exemple 2:
10
?{?[(?])?)
Expected output: 3

Exemple 3:
4
]??(
Expected output: 0
*/

int NumberOfWaysToReplace(int N, std::string sequence);

std::unordered_map<char, bool> symbole = { {'(', true}, {')', false}, {'[', true}, {']', false}, {'{', true},{'}', false} };
std::unordered_map<char, char> association = { {')', '('}, {']', '['}, {'}', '{'} };

int main()
{
	int N = 0;
	std::string sequence = "";
	std::cin >> N;
	std::cin >> sequence;

	std::cout << "Number of posibility: " << NumberOfWaysToReplace(N, sequence);
	


    return 0;
}


int NumberOfWaysToReplace(int N, std::string sequence)
{
	std::string stack;

	int possibility = 0;


	for (int i = 0; i < N; i++)
	{
		if (sequence[i] == '?')
		{

		}
		else if (symbole[sequence[i]])
		{
			stack += sequence[i];
		}
		else
		{
			if (!stack.size())
			{
				return 0;
			}
			if (stack.back() == association[sequence[i]])
			{
				stack.pop_back();
			}
			else
			{
				return 0;
			}
		}
	}

	return possibility;
}