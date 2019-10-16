#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/sort.h"
#include "../src/circular_sector.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../test/ut_sort.h"
#include "../src/terminal.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]){
      // argv you can see makefile "bin/geo input.txt output.txt area inc"
      // argv[1] = input.txt, argv[2] = output.txt, argv[3] = area, argv[4] = inc
      // implement reading input.txt
      // compose the string to Terminal(** Input string **)
      // **Input string**  Example: "Ellipse (6,5) Triangle (3,0,0,2,-3,0) CircularSector (8,40) area inc"
      // call showResult() to get result
      // write the result to output.txt
      // Don't hard code!!!

      string line ;
      ifstream fin(argv[1]);

      if( fin.is_open() )
      {
          getline(fin , line);
      }
      /*else
      {
          cout << "File not open !" << endl;
      }*/
      fin.close();
      /*
      std::cout << "++++++++++++++++++++" << '\n';
      std::cout << "Line : " << line << '\n';
      std::cout << "++++++++++++++++++++" << '\n';

      std::cout << "--------------------" << '\n';
      std::cout << "argv[0] : " << argv[0] << '\n';
      std::cout << "argv[1] : " << argv[1] << '\n';
      std::cout << "argv[2] : " << argv[2] << '\n';
      std::cout << "argv[3] : " << argv[3] << '\n';
      std::cout << "--------------------" << '\n';
      */

      vector<string> resultStr;
      resultStr.push_back(Terminal(line+" "+argv[3]+" "+argv[4]).showResult() );
      //cout << Terminal(line+" "+argv[3]+" "+argv[4]).showResult() << endl;
      ofstream fileout;
      fileout.open("output.txt", ios::out);
      if(fileout.is_open())
      {
          //cout << "JJJJ" << endl;
          vector<string>::iterator iter = resultStr.begin();

          for ( ; iter != resultStr.end() ; iter++ )
          {
              fileout << *iter ;
          }

          fileout.close();
      }

      //cout << "JJJBBB" <<endl;


      return 0;
}
