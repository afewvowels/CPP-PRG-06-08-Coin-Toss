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
#include <random>

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
    // Data validation
    while(!cin || intCoinTosses <= 0 || intCoinTosses > 100)
    {
        cout << "ERROR: Please enter a positive integer value between 1 and 100:\n";
        cin.clear();
        cin.ignore();
        cin >> intCoinTosses;
    }
    
    // Run this loop until the user-entered number has been reached
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
        // Error message if returned in is not 1 or 2;
        else
        {
            cout << "ERROR: BAD NUMBER GENERATED" << endl;
        }
    }
    
    return 0;
}

int coinToss()
{
    int intResult;
    
    // Use random_device to generate engine seed value
    random_device rd{};
    
    // Use Mersenne twister engine (cool name) to generate pseudo-random numbers
    // Seeded with random from above
    mt19937 engine{rd()};
    
    // Uniform distribution on the interval 1 - 2
    uniform_int_distribution<int> distribution(1,2);
    
    // Puts the Mersenne twister engine into the uniform_int_distribution
    // call to get random numbers (either 1 or 2) for coin tosses
    intResult = distribution(engine);
    
    // debug used to output integer result
    // cout << intResult << endl;
    
    return intResult;
}

