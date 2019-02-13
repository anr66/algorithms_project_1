// You need to complete this program for a part of your first project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h> 


// 'BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"

int main()
{
	/* The library throws 'const char *' error messages when things go
	* wrong.  It's a good idea to catch them using a 'try' block like this
	* one.  Your C++ compiler might need a command-line option to compile
	* code that uses exceptions. */
	try
	{      
		//std::cout << "a couple of test cases for 3460:435/535 Algorithms!!!\n";
		

		//std::cout << "my big1 !!!\n";
		//std::cout << big1;
		//BigUnsigned big2 = BigUnsigned(1);
		
		//for (int i=0;i<400;i++) 
		//{
		//	big2 = big2*10 +rand();
		//}

		//std::cout << "my big2 !!!\n";
		//std::cout << big2;
		//std::cout << "my big3 = big1*big2 !!!\n";
		//BigUnsigned big3 = big1*big2;
		//std::cout << big3;
		//std::cout << "my big3/big2 !!!\n";
		//std::cout << big3/big2;

	}

	catch(char const* err)
	{
		std::cout << "The library threw an exception:\n" << err << std::endl;
	}

	return 0;
}


BigUnsigned generateBigInt()
{
	BigUnsigned big = BigUnsigned(1);
	for (int i = 0; i < 400; i++)
	{
		big = (big * 10) + rand();
	}
	
	return big1;
	
}

BigUnsigned modExp(x, y, m)
{
	if (y = 0)
	{
		return(1);
	}
	
	else
	{
		z = mod-exp(x, y div 2, m);
	}
	
	if (y % 2 = 0)
	{
		return(z * z mod m);
	}	
	
	else
	{
		return(x * z * z mod m);
	}
}


BigUnsigned fermatTest()
{
	BigUnsigned a1 = generateBigInt();
	BigUnsigned a2 = generateBigInt();
	
}








