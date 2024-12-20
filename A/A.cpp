/*
Author: JOURNOUD Lucas
Date: 2024-12-20
Website: Yandex Contest
Problems: Стажировка осень-зима 2024 | бэкенд | A. Кроссворд
*/

#include <iostream>
#include <vector>

std::string FindMinimalWord(int R, int C, std::vector<std::vector<char>>);
void CheckWordIsLexicogrtaphicallySmaller(std::string &MinimalWord, std::string wordToCompare);

int main()
{
	int R=0, C=0;
	std::cin >> R >> C;
	std::vector<std::vector<char>> grid(R, std::vector<char>(C));
	std::string line = "";

	for (int i = 0; i < R; ++i)
	{
		std::cin >> line;
		for (int j = 0; j < C; ++j)
		{
			grid[i][j] = line[j];
		}
	}

	std::cout << FindMinimalWord(R, C, grid);

	return 0;
}

std::string FindMinimalWord(int R, int C, std::vector<std::vector<char>> words)
{
	std::string minimalWord = "{{";
	for (int i = 0; i < R; i++)
	{
		std::string temp = "";
		for (int j = 0; j < C; j++)
		{
			if (words[i][j] != '#')
			{
				temp += words[i][j];
			}
			else
			{
				CheckWordIsLexicogrtaphicallySmaller(minimalWord, temp);
				temp.clear();
			}
		}
		CheckWordIsLexicogrtaphicallySmaller(minimalWord, temp);
	}

	for (int j = 0; j < C; j++)
	{
		std::string temp = "";
		for (int i = 0; i < R; i++)
		{
			if (words[i][j] != '#')
			{
				temp += words[i][j];
			}
			else
			{
				CheckWordIsLexicogrtaphicallySmaller(minimalWord, temp);
				temp.clear();
			}
		}
		CheckWordIsLexicogrtaphicallySmaller(minimalWord, temp);
	}

	return minimalWord;
}

void CheckWordIsLexicogrtaphicallySmaller(std::string &minimalWord, std::string wordToCompare)
{
	if (wordToCompare.length() >= 2 && wordToCompare < minimalWord)
	{
		minimalWord = wordToCompare;
	}
}

void TestExample(void)
{
	std::vector<std::vector<char>> grid1 = {
	{'y', 'a', 'n'},
	{'d', '#', 'e'},
	{'#', '#', 'x'}
	};

	std::vector<std::vector<char>> grid2 = {
	{'c', '#'},
	{'o', 'n'},
	{'t', 'e'},
	{'s', 't'}
	};

	std::vector<std::vector<char>> grid3 = {
		{'i', 'n', 't', 'e', 'r'},
		{'n', 's', 'h', 'i', 'p'}
	};

	std::cout << "sortie 1: " << FindMinimalWord(3, 3, grid1) << std::endl;
	std::cout << "sortie 2: " << FindMinimalWord(4, 2, grid2) << std::endl;
	std::cout << "sortie 3: " << FindMinimalWord(2, 5, grid3) << std::endl;
}