//
//  pcl.hpp
//  BuckyTutorial
//
//  Created by Tuna Ozerdem on 7/13/16.
//  Copyright © 2016 Tuna Ozerdem. All rights reserved.
//

#ifndef pcl_hpp
#define pcl_hpp

#include <stdio.h>
#include <iostream>
#include <string>



class   pcl{
    
public:
    pcl( );
    
private:
    int x;
    
friend void friendFunction(pcl &pclObj);
    
    
    
};

#endif /* pcl_hpp */
