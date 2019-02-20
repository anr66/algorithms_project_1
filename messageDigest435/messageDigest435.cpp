/***
   prepared for CS435 Project 1 part 2
**/

#include <string.h>
#include <iostream>
#include <fstream>
#include "sha256.h"
#include "BigIntegerLibrary.hh"


int main(int argc, char *argv[])
{
   //demonstrating how sha256 works
   //std::string input = "testing";
   //std::string output1 = sha256(input);
   //std::cout << "sha256('"<< input << "'):" << output1 << "\n";

   //demo bigInt works here
   //BigUnsigned a = stringToBigUnsigned("124338907642982722929222542626327282");
   //BigUnsigned b = stringToBigUnsigned("124338907642977775546469426263278643");
   //std::cout << "big a = " <<a<<"\n";
   //std::cout << "big b = " <<b<<"\n";
   //std::cout << "big a*b = " <<a*b<<"\n";

   //Second part of your project starts here
   if (argc != 3 || (argv[1][0]!='s' && argv[1][0]!='v'))
      std::cout << "wrong format! should be \"a.exe s filename\"";
   else {
      std::string filename = argv[2];

      //read the file
      std::streampos begin,end;
      std::ifstream myfile (filename.c_str(), std::ios::binary);
      begin = myfile.tellg();
      myfile.seekg (0, std::ios::end);
      end = myfile.tellg();
      std::streampos size = end-begin;
      std::cout << "size of the file: " << size << " bytes.\n"; //size of the file

      myfile.seekg (0, std::ios::beg);
      char * memblock = new char[size];
      myfile.read (memblock, size); //read file; it's saved in the char array memblock
      myfile.close();

      std::string copyOFfile = filename+".Copy";
      std::ofstream myfile2 (copyOFfile.c_str(), std::ios::binary);
      myfile2.write (memblock, size); //write to a file
      myfile2.close();

      //std::cout<<memblock;
      // sha256 hash the memblock array
      std::string memblockString(memblock);
      std::string memblock_hash = sha256(memblockString);
      BigUnsigned memblock_num = BigUnsigned(BigUnsignedInABase(memblock_hash, 16));

	  //std::string memblock_hash = sha256(memblock);
	  //BigUnsigned memblock_num = BigUnsigned(BigUnsignedInABase(memblock_hash, 16));

      //std::cout << memblock_unsigned << "\n";

      if (argv[1][0]=='s')
      {
         //std::cout << "\n"<<"Need to sign the doc.\n";
         std::cout << "Signing document..." << "\n";

         BigUnsigned d;
         BigUnsigned n;

         // read the text file
         std::ifstream d_n("d_n.txt");

         // if it worked..
         if (d_n.good())
         {
            // read the d and n numbers in string format
            std::string d_string;
            std::string n_string;
            std::getline(d_n, d_string);
            std::getline(d_n, n_string);
            d = stringToBigUnsigned(d_string);
            n = stringToBigUnsigned(n_string);
         }

         // create the signature and the file to store it
         BigUnsigned signature = modexp(memblock_num, d, n);
         std::ofstream sig_file(filename + ".signature");
         sig_file << bigUnsignedToString(signature);// << "\n";
         sig_file.close();

         std::cout << "Done" << "\n";
      }

      else if (argv[1][0]=='v')
      {
         //std::cout << "\n"<<"Need to verify the doc.\n";

         std::cout << "Verifying document...\n";

         BigUnsigned e;
         BigUnsigned n;

         // read the text file
         std::ifstream e_n("e_n.txt");

         // if it worked..
         if (e_n.good())
         {
            // read the e and n numbers in string format
            std::string e_string;
            std::string n_string;
            std::getline(e_n, e_string);
            std::getline(e_n, n_string);
            e = stringToBigUnsigned(e_string);
            n = stringToBigUnsigned(n_string);
         }

         // open the signature file
         BigUnsigned signature;
         std::ifstream sig_file(filename + ".signature");

         // if it worked..
         if (sig_file.good())
         {
            // grab the string from the file and make it an int
            std::string signature_string;
            std::getline(sig_file, signature_string);
            signature = stringToBigUnsigned(signature_string);
         }

         BigUnsigned test = modexp(signature, e, n);

         if (test == memblock_num)
         {
            std::cout << "Verification was successful, file unchanged\n";
         }

         else
         {
            std::cout << "Verification was unsuccessful, file has been changed\n";
         }

      }

      delete[] memblock;
    }

    return 0;
}
