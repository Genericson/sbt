// A test program for sbt::vec
//====================LICENSE====================//
// Copyright (c) 2013, Harrison Leadlay
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  1) Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//  2) Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//===============================================//

#include <cstdio>
#include <iostream>
#include <limits>
#include "vec.hpp"

bool inputValid() {
    if ( !std::cin.eof() && std::cin.fail() ) {
        std::cerr<<"INVALID INPUT!\n";
        std::cout<<"Try again:"<<std::endl;
        return false;
    }
    if ( std::cin.eof() )
        std::cerr<<"EOF ERROR, BAD MONKEY!!!\n";
    else
        return true;
}

void menu(int i) {
    //assumes following input is good
    //types assumed to be float by default
    switch (i) {
    case 0: //exit
        //opt is zero; loop will exit;
        break;
    case 1: //addition
        std::cout<<"( a + b ) where a and be are scalars"<<std::endl;

        break;
    case 2: //subtraction
        std::cout<<"( a - b ) where a and b are scalars"<<std::endl;
        break;
    case 3: //scalar multiplication
        std::cout<<"( s * u ) where a is a scalar and u is a vector"<<std::endl;
        break;
    case 4: //dot product
        std::cout<<"( u DOT v ) where u and v are vectors"<<std::endl;
        break;
    case 5: //cross product
        std::cout<<"( u X v ) where u and v are 3-dimensional vectors"<<std::endl;
        break;
    case 6: //norm
        std::cout<<"norm( u ) where u is a vector"<<std::endl;
        break;
    case 7: //normalize
        std::cout<<"normalize( u ) where u is a vector"<<std::endl;
        break;
    default:
        std::cout<<"\nNOT A MENU OPTION, TRY AGAIN"<<std::endl;
        break;
    }
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using  sbt::vec;           // general vector class
    using namespace sbt::fvec; // predefined float-type template aliases
    using namespace sbt::dvec; //     '      double float-type '    '
    using namespace sbt::bvec; //     '      boolean-type  '        '
    using namespace sbt::ivec; //     '   (unsigned) integer-type ' '

    for(int opt = -1; opt != 0; )
    {
        cout<<" 1: +     2: -     3: *\n"
            <<" 4: dot   5: cross\n"
            <<" 6: norm  7: normalize\n"
            <<" 0: exit\n"<<std::endl;

        // get option input;
        cout<<"operation? ";
        cin>>opt;
        // if cin worked, invoke menu
        if ( inputValid() ) {
            cout<<endl;
            menu(opt);
        }
        else {
            opt = -1;//make sure opt is at default error value;
            cin.clear();
            cin.ignore();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }


    //CHOOSE OPERATION MENU//
    // 1: +     2: -     3: *
    // 4: dot   5: cross
    // 0: exit

    //INPUT ARGUMENTS//
        //takes explicit types in input
        //takes explicit types in output

    //SHOW OUTPUT
        // option: show type

    return 0;
}


