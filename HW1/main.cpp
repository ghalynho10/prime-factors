/*
Author: Ghaly Nicolas Jules
Class: ECE6122
Last Date Modified: 09/14/2021
Description:
What is the purpose of this file?
*/

#include <iostream>
#include <fstream>
using namespace std;

bool GetPrimeFactors(const unsigned long uLImputNumber, string &strOutput)
{
    long primeFactor = 2;
    long changingInputNumber = uLImputNumber;

    if (changingInputNumber <= 1)
    {
        return false;
    }
    else
    {
        while (primeFactor <= changingInputNumber)
        {
            if (changingInputNumber % primeFactor == 0)
            {
                strOutput += to_string(primeFactor) + ", ";
                changingInputNumber /= primeFactor;
            }
            else if (changingInputNumber % primeFactor != 0)
            {
                primeFactor++;
            }
        }
        return true;
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    ofstream outputFile;
    outputFile.open("output1.txt", ios::out | ios::trunc);
    if (outputFile.is_open())
    {
        string output = "";
        long enteredNumber = atol(argv[1]);
        if (GetPrimeFactors(enteredNumber, output))
        {
            output = output.substr(0, output.size()-2);
            outputFile<<output;
            cout<<output;
        }
        else
        {
            cout << "This number has no prime factors \n";
        }
        outputFile.close();
    }
    else
    {
        cout << "Could not open file";
    }
    return 0;
}
