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
    bool inputHadDecimal = false; // - gpt, used for checking the decimal
    bool megavalidity = true; // jordan
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
        // below is from gpt ( LOST MY SAVE :)))))) See in progress comments )
        std::string trimmed = input; // initializes trimmed as what we will be using throughout
        // remove leading/trailing spaces (optional)
        trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r")); // gets rid of any leading whitespace
        trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1); // gets rid of any non leading whitespace

        size_t i = 0; // initializes size
        isNegative = false; // assumes its positive

        if (trimmed[i] == '+' || trimmed[i] == '-') { // checks the first character
            isNegative = (trimmed[i] == '-'); // if its negative makes the 
            ++i; // goes to the next number
        }

        bool foundDecimal = false; // this is used to track where decimal is, if it is there at all

        while (i < trimmed.size()) { // goes through the entire string
            char c = trimmed[i]; // the current character
            if (c == '.') { // checks for the decimal
                //if (foundDecimal) break; // checks if there already was a decimal
                    // i dont think this should actually break here
                if (foundDecimal) megavalidity = false; // jordan
                foundDecimal = true; // tracks the decimal
                inputHadDecimal = true; // tracks the decimal
                ++i; // next index
                continue; // NEXT IN LINE
            }

            //if (!isdigit(c)) break; // non-digit, invalid - gpt   
                // also, i think this shouldnt break either. isValid() should handle it

            if (!foundDecimal) { // add this to the wholenumbers
                wholePart += c;
            } else { // adds to the decimal numbers
                decimalPart += c;
            }
            ++i; // NEXT
        }

        // Handle empty whole part
        //if (wholePart.empty()) wholePart = "0"; // this needs to be changed ?
    }
    bool isValid() const { // will be used for checking if the full thing is valid
        // gpt also left this blank. Neat
        // Roadmap
            // checks the wholenumbers and decimals for proper placements

        // gpt
        if (!std::all_of(wholePart.begin(), wholePart.end(), ::isdigit)) return false; //
        if (!std::all_of(decimalPart.begin(), decimalPart.end(), ::isdigit)) return false; // these check if theres any non digits in the string
        if (wholePart.empty()) return false; // jordan; I AM ASSUMING THAT .123 SHOULD BE INVALID
        if (wholePart.empty() && decimalPart.empty()) return false; // checks for emptiness
        if (decimalPart.empty() && inputHadDecimal) return false; // jordan  checks for emptiness
        if (!megavalidity) return false; // jordan checks my handy-dandy inprogress check thing
    return true;
    }
    std::string add(const StringDouble& other) const {
        // will be used to add -123.456
        // while i appreciate gpt believing in me on the others, i havent a CLUE how to go about this one
            // will probably hand it back to her
        // Roadmap
            // gave up - handing this to gpt
        // from gpt
        // Prepare both whole and decimal parts
        std::string w1 = wholePart, w2 = other.wholePart;
        std::string d1 = decimalPart, d2 = other.decimalPart;

        // this is used for esnuring the decimals are aligned
        while (d1.size() < d2.size()) d1 += "0";
        while (d2.size() < d1.size()) d2 += "0";

        // ensures that the whole numbers are aligned
        while (w1.size() < w2.size()) w1 = "0" + w1;
        while (w2.size() < w1.size()) w2 = "0" + w2;
        
        // attempt one did not work. lets try this again !
        std::string full1 = w1 + d1;
        std::string full2 = w2 + d2;
        
        bool resultNegative = false;
        std::string result;

        // Determine how to handle sign
        if (isNegative == other.isNegative) {
            // Same sign → Add
            int carry = 0;
            for (int i = full1.size() - 1; i >= 0; --i) {
                int sum = (full1[i] - '0') + (full2[i] - '0') + carry;
                carry = sum / 10;
                result = char((sum % 10) + '0') + result;
            }
            if (carry > 0) result = char(carry + '0') + result;
            resultNegative = isNegative; // same as both
        } else {
            // Different sign → Subtract smaller from larger
            bool firstIsBigger = full1 >= full2;
            std::string bigger = firstIsBigger ? full1 : full2;
            std::string smaller = firstIsBigger ? full2 : full1;

            int borrow = 0;
            for (int i = bigger.size() - 1; i >= 0; --i) {
                int top = (bigger[i] - '0') - borrow;
                int bottom = (smaller[i] - '0');

                if (top < bottom) {
                    top += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }

                result = char((top - bottom) + '0') + result;
            }

            resultNegative = firstIsBigger ? isNegative : other.isNegative;
        }

        // Split result back into whole/decimal -gpt
        int decimalLength = std::max(d1.size(), d2.size());
        std::string resultWhole = result.substr(0, result.size() - decimalLength);
        std::string resultDecimal = result.substr(result.size() - decimalLength);

        // Trim leading zeros in whole -gpt
        resultWhole.erase(0, resultWhole.find_first_not_of('0'));
        if (resultWhole.empty()) resultWhole = "0";

        // Trim trailing zeros in decimal -gpt
        while (!resultDecimal.empty() && resultDecimal.back() == '0') {
            resultDecimal.pop_back();
        }

        // Build final result -gpt
        std::string finalResult = (resultNegative && resultWhole != "0" ? "-" : "") + resultWhole;
        if (!resultDecimal.empty()) {
            finalResult += "." + resultDecimal;
        }

        return finalResult; // hands the finished object back - gpt
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

    // gpt
        // i lost all the work i had done. see in progress comments
    std::string filename; // initializes the file
    std::cout << "\n Note that this expects x.x\ny.x\nc.x\nETC.\n";
    std::cout << "\nEnter the name of the input file:\n";
    std::getline(std::cin, filename); // reads the user input and store it to filename

    std::ifstream file(filename); // opens the file
    if (!file) { // error handle, same as the previous labs
        std::cerr << "\nError opening file: " << filename << "\n";
        return 1; // ends the program
    }

    std::string line; // initializes the variable line
    while (std::getline(file, line)) {
        StringDouble candidate(line);

        std::cout << "\nInput: " << line << "\n";

        if (candidate.isValid()) {
            StringDouble base("-123.456"); // creates the variable for add
            std::string result = candidate.add(base); // makes a result from add
            std::cout << "\nValid double. Sum with -123.456 = " << result << "\n\n"; // prints the result
        } else {
            std::cout << "\nInvalid double.\n\n";
        }
    }
    file.close(); // closes the file
    return 0; // ends the program
}

// in progress comments
    // have completed the roadmaps for each function
    // besides the add function, I feel as though I know how to do all of these - just would take time + energy(to deal with incorrect iterations)
        // going to take break, but will probably hand to gpt to complete out
            // the roadmaps, unless just blatantly wrong, should be sufficient for her to complete this without issue
    // GOOD NEWS
        // I finished this and then it didnt save !
        // lucky me :)))))))))))))))))))
        // need to restart from this point
        // going to use gpt to rewrite code, absolutely no time/energy to remake this:))))))))))))))))

// pre debugging
    // now that ive typed it AGAIN, going to start debugging. this is rough where i was before i lost all the functions
        // fun !
        
// debugging
    // mostly works, but its not doing add() right
    // YAY IT WORKS NOW I CAN GO TO SLEEP
        // still need to comment out the changes