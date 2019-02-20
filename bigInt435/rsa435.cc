// You need to complete this program for a part of your first project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h> 
#include <fstream>

// 'BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"


using std::ofstream;
using std::cout;

BigUnsigned generateBigInt(int digits);
BigUnsigned modExp(BigUnsigned x, BigUnsigned y, BigUnsigned m);
bool fermatTest(BigUnsigned n);
BigUnsigned generateBigPrime();
BigUnsigned generateE(BigUnsigned theta);
bool relativelyPrime(BigUnsigned x, BigUnsigned y);


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

		// generate
		BigUnsigned p = generateBigPrime();
		BigUnsigned q = generateBigPrime();

		// print them out
		cout << "p = " << p << "\n";
		cout << "q = " << q << "\n";

		// write p and q to a file
		ofstream p_q("p_q.txt");
		p_q << p << "\n";
		p_q << q << "\n";

		// multiply p and q to get n
		BigUnsigned n = p * q;
		cout << "n = " << n << "\n";

		// calculate theta
		BigUnsigned theta = (p - 1) * (q - 1);
		if (theta % 2 == 0)
		{
			theta++;
		}

		cout << "theta = " << theta << "\n";

		// calculate e using theta
		BigUnsigned e = generateE(theta);
		cout << "e = " << e << "\n";

		// calculate d
		BigUnsigned d = modinv(e, theta);
		cout << "d = " << d << "\n";

		// write e and n to a file
		ofstream e_n("e_n.txt");
		e_n << e << "\n";
		e_n << n << "\n";

		// write d and n to a file
		ofstream d_n("d_n.txt");
		d_n << d << "\n";
		d_n << n << "\n";

	}

	catch(char const* err)
	{
		std::cout << "The library threw an exception:\n" << err << std::endl;
	}

	return 0;
}


BigUnsigned generateBigInt(int digits)
{
	BigUnsigned big = BigUnsigned(1);
	for (int i = 0; i <= digits; i++)
	{
		big = (big * 10) + rand();
	}

	return big;
}


/*
BigUnsigned modExp(BigUnsigned x, BigUnsigned y, BigUnsigned m)
{
	BigUnsigned z;

	if (y == 0)
	{
		return(1);
	}

	else
	{
		z = modExp(x, y / 2, m);
	}

	if ((y % 2) == 0)
	{
		return(z * z % m);
	}	

	else
	{
		return(x * z * z % m);
	}
}
*/

bool fermatTest(BigUnsigned n)
{
	BigUnsigned a1 = generateBigInt(1);
	BigUnsigned a2 = generateBigInt(2);
	return (modexp(a1, n - 1, n) == 1) && (modexp(a2, n - 1, n) == 1);
}


BigUnsigned generateBigPrime()
{
	BigUnsigned x = generateBigInt(155);
	while (!fermatTest(x))
	{
		x = generateBigInt(155);
	}

	if (x % 2 == 0)
	{
		x++;
	}

	return x;
}


bool relativelyPrime(BigUnsigned x, BigUnsigned y)
{
	return gcd(x, y) == 1;
}


BigUnsigned generateE(BigUnsigned theta)
{
	BigUnsigned e = generateBigInt(25);
	while (!relativelyPrime(e, theta))
	{
		e = generateBigInt(25);
	}

	if (e % 2 == 0)
	{
		e++;
	}

	return e;
}





