// EECS 348 lab 10
// Double Precision
// INPUT: user file of numbers
// OUT: arithimetic operations
// Collaborators
    // self (past tense)
    // hrhwilliams (template)
        // I am extremely confused
// Additionall collaborations
    //GPT or google.
        // if its not specifically stated to be by gpt its by Jordan
// Jordan McCool
/// /3/30/2025
#include <iostream>
        // "declares objects and functions that enable programs to interact with input/output devices like the console"
#include <fstream>
        // Allows file input and output operations
#include <string> // google says i need this for reading string inputs
#include <vector>
        // "a dynamic array - a sequence container that can change in size during runtime - similar to C arrays"
#include <sstream>
        // Allows a method of treating strings as input or output streams
#include <algorithm>
        // includes various prebuilt algorithms   
        // these are taken from assignment 5, not sure which ones I will use at this point       
#include <iomanip> // this is new to this lab
    // iomanip
        // google:
            // allows for input/output manipulators
            // used here for setw and setprecision
        // neat
// these are just copied from previous labs
    // left comments intact

// Initial Comments
    // Needs to read string numbers from a file, keep as string throughout
    // If it is a valid double number, say so and add it with -123.456 (?)
        // okay is this meaning add every line that works, with that number, or take an input and add it in which 123.456 is just a placeholder
    // am VERY confused on how the test/grading file will be formatted
// Roadmap
    // I think a class will be able to do well here
        // could use this class to break apart the string into what it actually is
// Example:
    // class name
        // private
            // sign - holds the sign
            // whole numbers - thinking this could be a vector or something dynamic that stores the digits
            // period - this will store the period, basically seperating the decimals and whole numbers
            // decimals - stores the decimal places
        // public
            // various functions that could be useful for the part of checking if valid
            // validcheck - check if the format of the class is valid
            // printer - gotta have it
            // adder - rough
            // return
                // sign - will tell you if its positive
                // digits
// Post roadmap comments
    // will probably use gpt to speed up the process of creating this, now that the roadmap is complete
    // while i think i could use the practice, i think i cannot justify the energy spent troubelshooting WHILE making something
        // versus just troubleshooting AFTER getting *something*

// gpt (hybrid - jordan)
class StringDouble {
private:
    bool isNegative; // idea from gpt - instead of storing the sign, just store the true false nature of it
        // might need to edit this based on error handling
    std::string wholePart; // stores the whole numbers
    std::string decimalPart; // stores the decimal numbers
public:
    StringDouble(const std::string& input){ // will be handed the input line from the file
        parseString(input); // imediately calls parseString to sort the values
    }
    void parseString(const std::string& input){
        // this will be used for sorting the values of the string
        // gpt actually left this blank, specifically to allow me to try to figure it out first
            // she believes in me   
        // Roadmap
            // read the first character
                // if positive make postive, if negative make negative (obvious)
                // if not + or -
                    // set to positive then assign that character to the whole numbers
            // continue reading
                // stop when done
                // if a character is a decimal
                    // skip this character, but all further characters are added to decimalPart
            // this CAN have invalid double numbers
    }
    bool isValid() const { // will be used for checking if the full thing is valid
        // gpt also left this blank. Neat
        // Roadmap
            // checks the wholenumbers and decimals for proper placements
    }
    std::string add(const StringDouble& other) const {
        // will be used to add -123.456
        // while i appreciate gpt believing in me on the others, i havent a CLUE how to go about this one
            // will probably hand it back to her
        // Roadmap
            // gave up - handing this to gpt
    }
    std::string toString() const { // this will be used for printing it
        std::string result = (isNegative ? "-" : "") + wholePart; // combines the whole numbers with the sign
        if (!decimalPart.empty()){
            result += "." + decimalPart; // this was gpt's idea, was originally having it just add .0, but this will keep the interger form
        }
        return result; // will be called with the intention of printing this
    }
};

int main(){
    // Roadmap main()
        // needs to open a file from user
        // each line of the file needs to be handed to class
        // each instance of class needs to be checked validity
        // if valid add -123.456
        // regardless, print result (if invalid say "x is invalid")
}

// in progress comments
    // have completed the roadmaps for each function
    // besides the add function, I feel as though I know how to do all of these - just would take time + energy(to deal with incorrect iterations)
        // going to take break, but will probably hand to gpt to complete out
            // the roadmaps, unless just blatantly wrong, should be sufficient for her to complete this without issue