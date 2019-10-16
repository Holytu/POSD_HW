#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include <cstring>
#include <regex>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <exception>
#include <stdexcept>
#include "sort.h"
using namespace std;

class Terminal
{
public:
    void split(string &s, vector<string>& vec, const char delim)
    {
        vec.clear();
        istringstream iss(s);
        string temp;

        while (std::getline(iss, temp, delim)) {
            vec.emplace_back(move(temp));
        }
    }

    string modifyInputString(string &str)
    {
        bool open_paren = false;

        for (int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] == '(')
            {
                int cp_Index = i + 1;
                while( cp_Index < str.size() )
                {
                    if(str[cp_Index] == ')')
                    {
                        open_paren = true;
                        break;
                    }
                    cp_Index = cp_Index + 1 ;
                }
            }

            if(open_paren == true && str[i] == ' ')
            {
                int sp_Index = i;
                int sp_Num = 0;
                while(str[sp_Index] == ' ')
                {
                    sp_Num++;
                    sp_Index++;
                }
                str.erase(i, sp_Num);
            }
            if(open_paren == true && str[i] == ')')
            {
                open_paren = false;
            }
        }
        return str;
    }

    string String2Vec(string &sm_str)
    {
        sm_str.erase(0,1);
        sm_str.erase(sm_str.size() - 1, 1);
        return sm_str;
    }

    /*template<class T>
    void PrintVec(vector<T> vec)
    {
        cout << "Vector size(In void PrintVec) = " << vec.size() << endl;
        for (int i = 0 ; i < vec.size() ; i++ )
        {
            cout << i << " index : ";
            cout << vec[i] << endl;
        }
        cout << endl;
    }*/

    vector<Shape*> buildShapeVec(vector<string> &vec)
    {
        smatch sm1;
        int ShapeTth = 0;
        FunctionType = 0;
        order = 0;

        vector<Shape*> ShapeArray;

        // Capture String Shapes
        for (int i = 0 ; i < vec.size() ; i+=2 )
        {
            bool isAns = false;
            //cout << "In position ith = " << i << endl;
            // Capute type of shape

            ShapeTth = 0;
            if (regex_search(vec[i] , sm1 , regex("(CircularSector)(.*)") ) )   // First shape : CircularSector
            {
                ShapeTth = 1;
                if(sm1[0].compare("CircularSector") == 0)
                {
                    isAns = true;
                }
            }
            else if (regex_search(vec[i] , sm1 , regex("(Ellipse)(.*)") ) )     // Second shape : Ellipse
            {
                ShapeTth = 2;
                if(sm1[0].compare("Ellipse") == 0)
                {
                    isAns = true;
                }
            }
            else if (regex_search(vec[i] , sm1 , regex("(Triangle)(.*)") ) )    // Third shape : Triangle
            {
                ShapeTth = 3;
                if(sm1[0].compare("Triangle") == 0)
                {
                    isAns = true;
                }
            }

            // After capturing the tpye of shapes, you need to capute the values!
            if (ShapeTth == 1) // CircularSector
            {
                if (regex_search(vec[ i + 1 ] , sm1 , regex("([(]\\d+[,]\\d+[)])") ) )
                {
                    string inp = sm1[0];
                    string sm_str = String2Vec(inp);

                    vector<string> sss;
                    split(sm_str, sss , ',');

                    if(isAns == true)
                    {
                        CircularSector *c = new CircularSector( stod(sss[0]) , stod(sss[1]));
                        ShapeArray.push_back(c);
                    }
                    else
                    {
                        CircularSector *c = new CircularSector( 0 , 0 );
                        ShapeArray.push_back(c);
                    }
                    sss.clear();
                }
            }
            else if (ShapeTth == 2) // Ellipse
            {
                if (regex_search(vec[ i + 1 ] , sm1 , regex("([(]\\d+[,]\\d+[)])") ) )
                {
                    string inp = sm1[0];
                    string sm_str = String2Vec(inp);

                    vector<string> sss;
                    split(sm_str, sss , ',');

                    if(isAns == true)
                    {
                        Ellipse *c = new Ellipse( stod(sss[0]) , stod(sss[1]));
                        ShapeArray.push_back(c);
                    }
                    else
                    {
                        Ellipse *c = new Ellipse( 0 , 0 );
                        ShapeArray.push_back(c);
                    }
                    sss.clear();
                }
            }
            else if (ShapeTth == 3)// Triangle
            {
                if (regex_search(vec[ i + 1 ] , sm1 , regex("([(][-]?\\d+[,][-]?\\d+[,][-]?\\d+[,][-]?\\d+[,][-]?\\d+[,][-]?\\d+[)])") ) )
                {
                    string inp = sm1[0];
                    string sm_str = String2Vec(inp);

                    vector<string> sss;
                    split(sm_str, sss , ',');

                    if(isAns == true)
                    {
                        Triangle *c = new Triangle( stod(sss[0]) , stod(sss[1]) , stod(sss[2]) , stod(sss[3]) , stod(sss[4]) , stod(sss[5]) );
                        ShapeArray.push_back(c);
                    }
                    else
                    {
                        Triangle *c = new Triangle( 0, 0, 0, 0, 0, 0);
                        ShapeArray.push_back(c);
                    }
                    sss.clear();
                }
            }

            // Capture (1.) Area , (2.) Perimeter , (3.) SumOfSquares
            if ( regex_search(vec[i] , sm1 , regex("(area)(.*)") ) ) // Area
            {
                FunctionType = 1;
            }
            else if ( regex_search(vec[i] , sm1 , regex("(perimeter)(.*)") ) ) // perimeter
            {
                FunctionType = 2;
            }
            else if ( regex_search(vec[i] , sm1 , regex("(sumOfSquares)(.*)") ) )// sumOfSquares
            {
                FunctionType = 3;
            }

            // Order : inc , dec
            if ( regex_search(vec[ i + 1 ] , sm1 , regex("(inc)(.*)") )) // Inc
            {
                order = 1;
            }
            else if ( regex_search(vec[ i + 1 ] , sm1 , regex("(dec)(.*)") )) // Dec
            {
                order = 2;
            }

            if (ShapeTth == 0 && order == 0 && FunctionType == 0) // Not Ellipse, CircularSector , Triangle
            {
                vec.erase(vec.begin() + i);
                i = i - 2 ;
            }
        }
        return ShapeArray;
    }

    Terminal(string stri)
    {
        _str = stri;
        //cout << "Terminal _str = " << _str << endl;
        //string ss1 = "Ellipse (10,8) Triangle (3,0,0,4,-3,0) Triangle (6,0,0,4,-6,0) CircularSector (5,60) perimeter";
        string ss1 = _str; //True !


        /// Modify Input String.
        //This step is used to eliminate spaces between open_paren and closed_paren.
        string ms = modifyInputString(ss1);
        //cout << "Modifies String : "<< ms << endl;

        // Split Modified Input String and put them into vector array.
        vector<string> vec;
        split(ss1, vec, ' ');
        //PrintVec(vec);

        ShapeList = buildShapeVec(vec);
        //PrintVec(vec);
    }

    std::string showResult()
    {
        Sort* SortClass = new Sort(&ShapeList);

        string ReturnStr = "";
        if( order == 0 || FunctionType == 0)
        {
            throw error_info;
        }

        if (order == 1) // Inc
        {
            ReturnStr = ReturnStr + "[";
            if(FunctionType == 1) // area
            {
                AscendingComparison asc("area");
                SortClass->sortArea(asc);
                /*
                cout << "Inc Area!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();

                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->area() << " #### ";
                    if( (*iter)->area() == 0 )
                    {
                        iter = iter + 1;
                    }
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->area() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->area() ) + "]";
                    }
                }
            }
            else if (FunctionType == 2) // perimeter
            {
                AscendingComparison asc("perimeter");
                SortClass->sortPerimeter(asc);
                /*
                cout << "Inc Perimeter!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();
                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->perimeter() << " #### ";
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->perimeter() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->perimeter() ) + "]";
                    }
                }
            }
            else //FunctionType == 3  , sumOfSquares
            {
                AscendingComparison asc("sumOfSquares");
                SortClass->sortSumOfSquares(asc);
                /*
                cout << "Inc SumOfSquares!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();
                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->sumOfSquares() << " #### ";
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->sumOfSquares() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->sumOfSquares() ) + "]";
                    }
                }
            }

            return ReturnStr;
        }
        else if (order == 2) // Dec
        {
            ReturnStr = ReturnStr + "[";
            if(FunctionType == 1) // area
            {
                DescendingComparison dsc("area");
                SortClass->sortArea(dsc);
                /*
                cout << "Dec Area!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();
                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->area() << " #### ";
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->area() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->area() ) + "]";
                    }
                }
                return ReturnStr;
            }
            else if (FunctionType == 2) // perimeter
            {
                //cout << "Dec perimeter : "<< endl;
                DescendingComparison dsc("perimeter");
                SortClass->sortPerimeter(dsc);
                /*
                cout << "Dec Perimeter!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();
                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->perimeter() << " #### ";
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->perimeter() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->perimeter() ) + "]";
                    }
                }
                //return ReturnStr;
            }
            else //FunctionType == 3  , sumOfSquares
            {
                DescendingComparison dsc("sumOfSquares");
                SortClass->sortPerimeter(dsc);
                /*
                cout << "Dec SumOfSquares!!!" << endl << endl;
                */
                vector<Shape*>::iterator iter = ShapeList.begin();
                for ( ; iter != ShapeList.end() ; iter++ )
                {
                    //cout << (*iter)->sumOfSquares() << " #### ";
                    if(iter + 1 != ShapeList.end() )
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->sumOfSquares() ) + ", ";
                    }
                    else
                    {
                        ReturnStr = ReturnStr + to_string( (*iter)->sumOfSquares() ) + "]";
                    }
                }
            }

            return ReturnStr;
        }
        else // order == 0
        {
            throw std::string("Unuseful User Input!");
        }
    }

private:
    string _str = "";
    string error_info = "Unuseful User Input!";
    int FunctionType = 0;
    int order = 0;
    vector<Shape*> ShapeList;
};
#endif
