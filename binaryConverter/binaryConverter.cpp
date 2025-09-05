/*
 * Name: Huthsady Legend Boun
 * Professor Grace A. Comp
 * Class: CISP-2410-SVC
 * Date: 4 September 2025
 * Description: Takes any 16-bit binary number and converts it to its decimal form.
*/

#include <iostream>
#include <string>




// Used For Debugging Functions.
void debugPrinter(std::string debug_print)
{
    std::cout << debug_print;
}



// Function for allowing user to enter the binary number they wish to convert.
std::string getUserInput()
{
    // Local Variables
    std::string userInput;
    bool isSixteen = false;

    std::cout
        << "Please enter the 16-bit binary number you would like to convert!\n";

    while (isSixteen == false)
    {
        std::cin >> userInput;
        if (std::size(userInput) != 16)
        {
            std::cout << "Make sure the number you entered is 16-bits!\n";
        }
        if (std::size(userInput) == 16)
        {
            isSixteen = true;
            std::cout << "Valid Number Detected!\nProcessing.....\n";
        }
    }


    return userInput;
}






/* Takes the already inputted 16-bit binary and converts it to decimal
   it does this using an array with the powers of two already stored.
   The string is parsed as an array from left-to-right, and the 2^n are
   stored accordingly.
*/
int binaryConverter(std::string hexadecNum)
{
    // Local Variables
    int runningTotal = 0;
    int powersOfTwo[16] =
    {
      32768, 16384, 8192, 4096,
      2048, 1024,512, 256,
      128, 64, 32, 16,
      8, 4, 2, 1
    };

    for (int i = 0; i < std::size(hexadecNum); i++)     // Loops over the size of the string array.
    {
        // Uncomment for debug tooling.
        // std::cout << hexadecNum[i] << "\n";
        if (hexadecNum[i] == '1')
        {
            runningTotal += powersOfTwo[i];
        }
    }
    return runningTotal;
}



// Main function... every c++ program needs one!
int main()
{
    //debugPrinter(getUserInput());
    std::cout << "Your binary conversion is: " << binaryConverter(getUserInput());
};
