////
////  main.cpp
////  BuckyTutorial
////
////  Created by Tuna Ozerdem on 6/23/16.
////  Copyright © 2016 Tuna Ozerdem. All rights reserved.
////
#include "TunaClass.hpp"
#include "itk.hpp"
#include "gstik.hpp"
#include "Birthday.hpp"
#include "People.hpp"
#include "pcl.hpp"
#include "This concept.hpp"
#include "Inheritance.hpp"
#include "Inheritance Concept.hpp"


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//////////////////////////////////////////////////////// CLASSES ////////////////////////////////////////////////////////

class BuckyClass{

public:
    
    BuckyClass(string  x){                //////Constructor
    
        setName(x);
        
    
    
    }
    void setName(string passedName){
        name = passedName;
    }
    
    string getName(){
        return  name;
    }
    
    
private:
    string name;

};

class Enemy {

public:
    void setAttackPower(int a){
        AttackPower = a ;
    }

protected:
    int AttackPower;
    
};

class Ninja: public Enemy {
    
public:
    void attack(){
    
     cout<< "I am Ninja ninja chop! - " << AttackPower <<endl;
    }
};

class Monster: public Enemy {
    
public:
    void attack(){
        
        cout<< "I am Monster, Monster eat YOU! - " << AttackPower*2 <<endl;
    }
};

class Turkey{
    
public:
    //virtual void attack () = 0; -> This means that every class that is inherited from the base clase MUST iplement the attack function!!!
   //                                and it is called PURE VIRTUAL FUNCTION
    virtual void attack (){
        
    }
private:
protected:

};

class Ataturk: public Turkey{
    
public:
    void attack(){
        cout<< "Ataturk is the best f the rest:" <<   endl;
    }
    
private:
protected:
    
};

class Erdogan: public Turkey{
    
public:
    void attack(){
        cout<< "YOL yaptik YOL " <<   endl;
    }
private:
protected:
    
};

template< class T >
class classTemplate{

public:
    classTemplate(T passedValue_1, T passedValue_2){
    
        x = passedValue_1;
        y = passedValue_2;
    
    }
    T bigger();         // I am gonna build this function outside of the class. In order to do that I have to
                        // tell c++ that the function I am gonna working with will have template of this class.
private:
    T x,y;


};
template< class T>
T classTemplate<T>::bigger(){      // First T on the left defines the return Type but the other T is just a stupid rule.
   
    return (x>y?x:y);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////  FUNCTIONS  ////////////////////////////////////////////////////////////////////////////////////

void passByReference(int *passedPointer){
    *passedPointer   =   69;
}

void friendFunction(pcl &pcl_Obj){
    pcl_Obj.x = 11;
    
    cout<<"A friend function from main  just changed a private variable inside pcl class that was set to 99 but now is: "<< pcl_Obj.x << endl;
    
};

template< class T, class U >//you must have this on the top of the everyfunction where you want to work with different data types but treat them as same
T functionTemplate(T x,U y ){
    
    return (x + y);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
    string Name = "Guleycan";

    BuckyClass  buckyObject("This is constructor!");
    
    string insideConstructor = buckyObject.getName();
    cout<<buckyObject.getName() << endl;
    
    buckyObject.setName(Name);
    cout<<buckyObject.getName()<<endl;
    // insert code here...
    TunaClass   tunaObject;                 //  When Created the tunaObject (to access TunaClass) The constructure does his job automatically
    
    itk         itkObject;                  //  When Created the itkObject (to access itk) The constructure does his job automatically
    
  
    
    int fish = 99;
    int *pointerFish;
    pointerFish =   &fish;
    
    
    cout<< "pointerFish: "<<pointerFish<<endl;
    cout<<"*pointerFish: "<< *pointerFish<<endl;
    passByReference(pointerFish);
    cout<<"Fish variable after going into passByReference: "  << fish<<endl; // I could also write cout<<""<< *pointerFish<<endl; //same thing
    
    
    itk *itkPointer = &itkObject;
    itkPointer->printCrap();                //  Printed from itk class using printCrap function accessed by the itkPointer:
    
    
    
    //////////////  IF YOU WANNA HAVE CONSTANT OBJECT THEN YOU HAVE TO HAVE A CONSTANT FUNCTION AS WELL /////////////
    const gstik       gstikObject;                //  When Created the gstikObject (to access gstik) The constructure does his job automatically
    string  Bla = "a General String";
    string  *BlaPointer      =  &Bla;
    cout    << "*BlaPointer" <<*BlaPointer <<  endl;
    const  gstik   *gstikPointer    =   &gstikObject;
    gstikPointer->aConstantFunction(BlaPointer);
    cout    << "BlaPointer: " << *BlaPointer <<  endl;
    
    
    
    
    
    //////////////      COMPOSITION     //////////////
    Birthday    bo(03,06,1991);
    
    People  people("Tuna",  bo);
    
    people.printInfo();
    
    ///////////////////////////////////////////////////
    
    //////////////      FRIEND     //////////////
    
    pcl pcl_Obj;
    
    friendFunction(pcl_Obj);
    
    
    ///////////////////////////////////////////////////
    
    //////////////      FRIEND     ////////////// (Does the same thing as above instead this time with a pointer )
    
    pcl *pcl_objPtr = &pcl_Obj;
    friendFunction(*pcl_objPtr);
    
    ///////////////////////////////////////////////////
    
    //////////////      THIS     //////////////
    ThisConcept thisObject(99);
    thisObject.printCrap();
    
    ///////////////////////////////////////////////////
    
    //////////////      INHERITANCE     //////////////
    
    cout<< "////////////// INHERITANCE ////////////// " << endl;
    
    Mother  motherObj;
    cout<< "motherObj.shout():" << endl;
    motherObj.shout();
    
    cout<< "Now daughter actually shouts but because the daughter is inherited from Mother" << endl;
    Daughter    daughterObj;
    daughterObj.shout();
    
    cout<< "///////////////////////////////////////////////////" << endl;
    
    //////////////      POLYMORPHISM     ////////////// ( Usage of member from a super class inside a derived class and have the same function in both derived classes but to have different responses )
    
    cout<< "////////////// POLYMORPHISM ////////////// " << endl;
    
    Enemy   *enemy1_Obj_Ptr;
    Monster monsterObj;
    enemy1_Obj_Ptr = &monsterObj;
    enemy1_Obj_Ptr -> setAttackPower(29);
    monsterObj.attack();
    
    
    Enemy   *enemy2_Obj_Ptr;
    Ninja   ninjaObject;
    enemy2_Obj_Ptr = &ninjaObject;
    enemy2_Obj_Ptr -> setAttackPower(29);
    ninjaObject.attack();
    
    cout<< "////////////POLYMORPHISM:HOW IT IS BETTER USED ///////////////////" << endl;
    
    Erdogan erdoganObj;
    Ataturk ataturkObj;
    
    Turkey *Enemy = &erdoganObj;
    Turkey *Savior = &ataturkObj;
    
    Enemy->attack();
    Savior->attack();
    
    cout<< "///////////////////////////////////////////////////"<< endl;
    
    
    ///////////////////////////////////////////////////
    cout<< "////////////FUNCTION TEMPLATES ///////////////////" << endl;
    int a = 12;
    float b = 13;
    
    int zika = functionTemplate(a,b); // this func demos. how can I take two different dataTypes and send it to a function and work with them with a template dataType that I created to treat those dataTypes as they were same in the first place.
    
    // NOTE: I am not sure about what to put for returned values type i.e. zika could be int,float but when I tried char it didn't show anything at the output.
    cout<< "zika: " << zika << endl;
    cout<< "///////////////////////////////////////////////////"<< endl;
    
    cout<< "////////////CLASS TEMPLATES ///////////////////" << endl;
    
    classTemplate<int> classTemplateObject(29,40); // I need to tell c++ that I am sending an int so it can replace with the template.
    cout<<"Bigger Value: "<<classTemplateObject.bigger()<<endl;
    cout<< "///////////////////////////////////////////////////"<< endl;
    
    
    cout << "Hello, World!\n";
    return 0;
}

//#include <iostream>
//#include <string>
//#include <stdio.h>
//#include <cstdlib>
//#include <array>
//#include <vector>
//#include <math.h>
//#include <iomanip>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    
//    int keyPad_0[2] = {6,4};
//    int keyPad_1[2] = {6,8};
//    int keyPad_2[2] = {7,9};
//    int keyPad_3[2] = {4,8};
//    int keyPad_4[3] = {1,9,0};
//    
//    int keyPad_6[3] = {1,7,0};
//    int keyPad_7[2] = {6,2};
//    int keyPad_8[2] = {1,3};
//    int keyPad_9[2] = {4,2};
//    
//    float T;
//    cout << "How many moves do you want to make?";
//    cin >> T;
//    
//    int size = (sizeof(keyPad_0)/sizeof(*keyPad_0));
//    
//    int randChosenValue = keyPad_0[ rand() % size ];
//    
//    int sum = 0;
//    int S[int(T)+1];
//    int  currentArray[3];
//    
//    for (int i = 0; i<T; i++){
//     
//    //randChosenValue ya bakarak bi tane array sec.
//    // o arrayi cagir ve randomly icinden bi tane sayi sec
//    // o sayiyi sum a ekle
//    // o sayiya bakarak yeni arrayi cagir.
//        
//        switch ( randChosenValue ) {
//            case 0:
//                
//                for (int i =0 ; i< (sizeof(keyPad_0)/sizeof(*keyPad_0)) ; i++){
//                
//                    currentArray[i] =  keyPad_0[i];
//                
//                }
//                
//                break;
//                
//                
//            case 1:
//                for (int i =0 ; i< (sizeof(keyPad_1)/sizeof(*keyPad_1)) ; i++){
//                    
//                    currentArray[i] =  keyPad_1[i];
//                    
//                }
//                break;
//                
//            case 2:
//                for (int i =0 ; i< (sizeof(keyPad_2)/sizeof(*keyPad_2)) ; i++){
//                    
//                    currentArray[i] =  keyPad_2[i];
//                    
//                }
//                break;
//                
//            case 3:
//                for (int i =0 ; i< (sizeof(keyPad_3)/sizeof(*keyPad_3)) ; i++){
//                    
//                    currentArray[i] =  keyPad_3[i];
//                    
//                }
//                break;
//                
//            case 4:
//                for (int i =0 ; i< (sizeof(keyPad_4)/sizeof(*keyPad_4)) ; i++){
//                    
//                    currentArray[i] =  keyPad_4[i];
//                    
//                }
//                break;
//                
//            case 6:
//                for (int i =0 ; i< (sizeof(keyPad_6)/sizeof(*keyPad_6)) ; i++){
//                    
//                    currentArray[i] =  keyPad_6[i];
//                    
//                }
//                break;
//                
//            case 7:
//                for (int i =0 ; i< (sizeof(keyPad_7)/sizeof(*keyPad_7)) ; i++){
//                    
//                    currentArray[i] =  keyPad_7[i];
//                    
//                }
//                break;
//                
//            case 8:
//                for (int i =0 ; i< (sizeof(keyPad_8)/sizeof(*keyPad_8)) ; i++){
//                    
//                    currentArray[i] =  keyPad_8[i];
//                    
//                }
//                break;
//            case 9:
//                for (int i =0 ; i< (sizeof(keyPad_9)/sizeof(*keyPad_9)) ; i++){
//                    
//                    currentArray[i] =  keyPad_9[i];
//                    
//                }
//                break;
//                
//            default:
//                // Code
//                break;
//        }
//         
//        
//        cout<< "s: " << sum <<endl;
//        S[i] = sum;
//        sum = sum + randChosenValue;
//        
//        randChosenValue = currentArray[ rand() % size ];
//        
//        
//    }
//    
//    S[int(T)] = sum;
//    int sizeOf_S = (sizeof(S)/sizeof(*S));
//    
//    cout<<"sum=" << sum << endl;
//    cout<<"S[T]: "<< S[int(T)] << endl;
//    float summedS = 0;
//    
//    for(int i=0; i<(sizeof(S)/sizeof(*S)); i++ ){
//        
//        summedS= summedS + S[i];
//        
//    
//    }
//    cout<<"summed S:" << summedS<< endl;
//    float expVal = summedS / sizeOf_S;
//    
//  
//    cout << fixed << "Expected value of S % " << T <<" is :"<< setprecision(10) << fmod( expVal, T ) << std::endl;
//    
//    float std = 0;
//    
//    for(int i=0; i < (sizeof(S)/sizeof(*S)); i++ ){
//        
//        std = std + ((S[i] - expVal)*(S[i] - expVal));
//
//    }
//    
//    std = sqrt(std / (sizeOf_S - 1));
//    cout<< "standard deviasion of S % " <<T<<" is: "<< fmod(std,T) << endl;
//    
////    for (int i=0; i< sizeOf_S; i++){
////        cout<< S[i] << endl;
////    }
//    int divisableByFiveandSevenCounter = 0;
//    int divisableBySevenCounter = 0;
//   
//    for (int i = 0 ; i < sizeOf_S; i++){
//        
//        if (S[i] % 5 == 0 && S[i] % 7 == 0 ){
//            
//               //
//            divisableByFiveandSevenCounter++;
//           
//        }
//        
//        if (S[i] % 7 == 0 ){
//            
//            
//            divisableBySevenCounter++;
//            
//        }
//
//        
//    }
//    
//    float probOfDivByFiveandSeven = divisableByFiveandSevenCounter / sizeOf_S;  //P(A KESISIM B)
//    float probOfDivBySeven = divisableBySevenCounter / sizeOf_S;                // P(A)
//    
//    double ConditionalProb = probOfDivByFiveandSeven / probOfDivBySeven;        //P(A KESISIM B) / P(A)
//
//    
//    cout<<"probability that the sum S is divisible by 5, given that it is divisible by 7 :" << ConditionalProb<< endl;
//    
//}

//
//#include <string.h>
//#include <iostream>
//#include <string>
//#include <stdio.h>
//#include <cstdlib>
//#include <array>
//#include <vector>
//#include <math.h>
//#include <iomanip>
//using namespace std;
//int main ()
//{
//    // Read the file ----------
//    FILE* fp = fopen("/Users/tuna/Downloads/Historic_Secured_Property_Tax_Rolls.csv", "rb");
//    if (fp == NULL)
//        return -1;
//    fseek(fp, 0, SEEK_END);
//    
//    long size = ftell(fp);
//    
//    fseek(fp, 0, SEEK_SET);
//    char *pData = new char[size + 1];
//    fread(pData, sizeof(char), size, fp);
//    fclose(fp);
//    // Read the file ----------
//    
//    // Parse the file content ----------
//    char* pch;
//    pch = strtok (pData, "|");
//    int iCpt = 1;
//    while (pch != NULL)
//    {
//        cout<< "sads"<<endl;
//        if (iCpt == 3 || iCpt == 4 || iCpt == 5)
//        {
//            printf ("%s\n", pch);
//        }
//        pch = strtok (NULL, "|");
//        iCpt++;
//    }    // Parse the file content ----------
//    return 0;
//}




































