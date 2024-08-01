#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

#define arraySize 26  // Define the number of letters in the English alphabet

// Structure to store each letter and its corresponding Morse code

struct morse {
  char letter;
  const char * code;
};

// Initialize Morse code table for each letter in the alphabet
morse morseTable[26] = {
       {'A', ".-"},     {'B', "-..."},   {'C', "-.-."},
       {'D', "-.."},    {'E', "."},      {'F', "..-."},
       {'G', "--."},    {'H', "...."},   {'I', ".."},
       {'J', ".---"},   {'K', "-.-"},    {'L', ".-.."},
       {'M', "--"},     {'N', "-."},     {'O', "..."},
       {'P', ".--."},   {'Q', "--.-"},   {'R', ".-."},
       {'S', "---"},    {'T', "-"},      {'U', "..-"},
       {'V', "...-"},   {'W', ".--"},    {'X', "-..-"},
       {'Y', "-.--"},   {'Z', "--.."}
};

// Function to decode Morse code into an English letter
int decodeMorse(const char * target) {
  for (int i = 0; i <= arraySize; i++) {  // Iterate through the Morse table
    if (strcmp(target, morseTable[i].code) == 0) { // Compare input Morse code with table entries
      return i;  // Return the index of the matching lette
    }
  }
  return -1;  // Return -1 if Morse code is not found
}

// Function to encode an English letter into Morse code
int encodeMorse(char target) {
  for (int i = 0; i <= arraySize - 1; i++) {
    if (target == morseTable[i].letter) {
      return i;
    }
  }
  return -1;
}

int main() {
  while (true) {// Infinite loop to continuously accept user input
    printf("Enter a code or letter: ");
    string userInput;
    cin >> userInput;

    if (userInput == "exit") {
      printf("Exiting program.\n");
      break; // Exit the loop and end the program
    }

    int index = 0;

    if (userInput.length() == 1) {
      index = encodeMorse(toupper(userInput[0]));
      if (index != -1) {
        printf("The letter you entered: %c has been encoded to: %s\n", morseTable[index].letter, morseTable[index].code);
      } else if (index == -1) {
		  if(userInput[0] == '.' || userInput[0] == '-' ){
			  index = decodeMorse(userInput.c_str());
			  printf("The code you entered: %s has been decoded to: %c\n", morseTable[index].code, morseTable[index].letter );
		  }
		  else {
        printf("Error letter absent in look up table\n");
      }
	  }
    } else if (userInput.length() > 1) {
      index = decodeMorse(userInput.c_str());
      if (index != -1) {
        printf("The code you entered: %s has been decoded to: %c\n", morseTable[index].code, morseTable[index].letter );
      } else if (index == -1) {
        printf("Error code absent in look up table\n");
      }
    }
  }
}
