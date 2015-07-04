#include "StringTools.h"

std::string str::toUpper(std::string str)
{
	for (unsigned int i = 0; i < str.size();i++)
	{
		str.at(i)=chrToUpper(str.at(i));	
	}

	return str;
}

// Homebrew ;-)
char str::chrToUpper(char chr)
{
	for (unsigned int i = 0; i < ALPHACOUNT; i++)
	{
		if (chr==ALPHAS_LC[i])
		{
			return ALPHAS_UC[i];
		}
	}

	return chr;
}