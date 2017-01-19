//
//  People.hpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/26/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#ifndef People_hpp
#define People_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "Birthday.hpp"

using namespace std;



class   People{
public:
    People(string name, Birthday    birthObject);   //Constructure
    void    printInfo();

private:
    string      namePrivate;
    Birthday    birthObjectPrivate;



};




#endif /* People_hpp */

