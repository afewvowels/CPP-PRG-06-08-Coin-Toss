//
//  main.cpp
//  PRG-6-8-Coin-Toss
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  This program runs slowly because time(0) counts seconds.
//  Cannot get more than 1 random result per second and sometimes
//  the case falls through and returns no value so we have
//  to wait for the next second or the next next second, etc.


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int coinToss();

int main()
{
    int intCoinTosses,
        intResult;
    
    string strResult;
 
    cout << "Please enter the number of times\n"
         << "you would like to flip the coin:\n";
    cin >> intCoinTosses;
    
    while(!cin || intCoinTosses <= 0 || intCoinTosses > 100)
    {
        cout << "ERROR: Please enter a positive integer value between 1 and 100:\n";
        cin.clear();
        cin.ignore();
        cin >> intCoinTosses;
    }
    
    for(int i = 1 ; i <= intCoinTosses ; i++)
    {
        intResult = coinToss();
        
        if(intResult == 1)
        {
            strResult = "Heads";
            cout << strResult << endl;
        }
        else if(intResult == 2)
        {
            strResult = "Tails";
            cout << strResult << endl;
        }
        //Catches bad return values and decrements i
        //so that the program tries again.
        //Program will always output desired number of results
        //But may need to call coinToss() many more times.
        else
        {
            //cout << "ERROR" << endl;
            i--;
        }
    }
    
    return 0;
}

int coinToss()
{
    int intResult,
        intTempTime;
    
    float fltClock;
    
    intTempTime = time(0);
    
    //Test when intTempTime is the same as time(0)
    //It is sometimes false and falls through
    //With no returned value
    while(intTempTime == time(0))
    {
        while(intTempTime != time(0))
        {
            fltClock = time(0);
            
            unsigned seed = time(0);
            
            srand(seed);
            
            intResult = rand() % 2;
            
            intResult += 1;
            
            //Used for debug to see random outputs with heads/tails result
            //cout << intResult << endl << time(0) << endl;
            
            return intResult;
        }
    }
    return 0; // Default value to return, will cause main to decrement and try again
}

