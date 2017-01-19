//
//  itk.cpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 6/24/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#include "itk.hpp"
#include <string>
#include <iostream>

using namespace std;


itk::itk()
{
    cout << "This is constructure from itk" << endl;
}

void itk::printCrap(){
    cout<< "Printed from itk class using printCrap function accessed by the itkPointer: " << endl;
}