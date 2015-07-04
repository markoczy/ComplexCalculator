#include <iostream>

const char ALPHAS_LC[] =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
						//   0 ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9

							'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
						//	10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 ,

							'u', 'v', 'w', 'x', 'y', 'z' };
						//	20 , 21 , 22 , 23 , 24 , 25

const char ALPHAS_UC[] =  { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
						//   0 ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9

							'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
						//	10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 ,

							'U', 'V', 'W', 'X', 'Y', 'Z' };
						//	20 , 21 , 22 , 23 , 24 , 25

const int ALPHACOUNT = 26;

namespace str
{
	std::string toUpper(std::string str);
	char chrToUpper(char chr);
}