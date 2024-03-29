// L�onard Berney, Sacha Bron

#ifndef Dictionary_h
#define Dictionary_h

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "TernarySearchTrie.h"

class Dictionary
{
private:
	std::set<std::string> dictionary_std;
	TernarySearchTrie dictionary_tst;

	bool useStd;

public:
	Dictionary(const std::string& filename, bool mode) : useStd(mode)
	{
		std::string line;

		std::ifstream s(filename);
		while (std::getline(s, line))
		{
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
			if (useStd)
			{
				dictionary_std.insert(line);
			}
			else
			{
				dictionary_tst.insert(const_cast<char*>(line.c_str()));
			}
		}
		s.close();
	}

	// v�rifie si un mot est dans le dictionaire 
	bool checkWord(const std::string& word)
	{
		if (useStd)
		{
			return dictionary_std.find(word) != dictionary_std.end();
		}
		else
		{
			return dictionary_tst.contains(const_cast<char*>(word.c_str()));
		}
	}

	// pas impl�ment�
	std::vector<char*> findPartialMatches(const char* word)
	{
		return dictionary_tst.wildCardMatch(word);
	}
};

#endif