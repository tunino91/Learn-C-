//
//  This concept.cpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 7/13/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#include "This concept.hpp"


#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
ThisConcept::ThisConcept(int num):
privatenum(num)
{

}

void ThisConcept::printCrap(){
    cout << "/////////// This Concept ///////////  " << endl;

    cout << "privatenum = "   << privatenum  << endl;
    cout << "this->privatenum = "   << this->privatenum  << endl; //// 'this:' stores the address of the objet that was created in main (thisObject). so it behaves like a pointer to that object!!!!!!!!
    cout << "(*this).privatenum = "   << (*this).privatenum  << endl;
    cout << "////////////////////////////////  " << endl;
}