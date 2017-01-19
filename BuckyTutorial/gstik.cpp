//
//  gstik.cpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/24/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#include "gstik.hpp"
#include <iostream>
#include <string>

using namespace std;

gstik::gstik(){

    cout<<"This is constructor of gstik"<<endl;
    

}

/*string*/void   gstik::aConstantFunction(string    *passedWord)  const{

    cout    <<  "I am the constant function from gstik class"   <<  endl;
    *passedWord  =   "a General String has been changed by aConstantFuntion inside gstik class";
    //return  *passedWord;
}

//
//gstikHeaderdaBaskaClass::gstikHeaderdaBaskaClass(){
//
//    cout<<"basd"<<endl;
//}

