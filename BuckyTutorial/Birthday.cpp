//
//  Birthday.cpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/26/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#include "Birthday.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


Birthday::Birthday(int day,int month,int year)
:dayPrivate(day),monthPrivate(month),yearPrivate(year)
{




}

void    Birthday::printBirthday(){

    cout<< dayPrivate <<"/"<<monthPrivate<<"/"<<yearPrivate<<endl;

}
