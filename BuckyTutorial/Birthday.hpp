//
//  Birthday.hpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/26/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#ifndef Birthday_hpp
#define Birthday_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class   Birthday{
    
public:
    Birthday(int day, int month,  int year);
    
    void printBirthday();
    
private:
    int dayPrivate;
    int monthPrivate;
    int yearPrivate;
    

};
#endif /* Birthday_hpp */