//
//  People.cpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/26/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#include "People.hpp"
#include "Birthday.hpp"

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

People::People(string name, Birthday    birthObject)
:namePrivate(name),birthObjectPrivate(birthObject)
{
    


}

void    People::printInfo(){
    
    cout    <<  namePrivate <<  " was born in: "  ;
    birthObjectPrivate.printBirthday();

}