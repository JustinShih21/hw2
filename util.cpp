#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>
#include <set>

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

  // Create an empty string
  std::string w = "";
  std::set<std::string> s;

  // For loop for parsing, goes through all characters in the string
  for (size_t i =0; i < rawWords.length(); i++) {

    // Adds the word to the set if its space or punctuation
    if (rawWords[i] == ' ' || ispunct(rawWords[i])) {
      // Checks to make sure its 2 characters
      if (w.length() > 1){
        s.insert(w);
      } 
      // Resets word
      w = "";

    }
    // Adds the character to the word otherwise
    else {
      w += rawWords[i];
    }
  }
  
  // Add the final word in the list if it's bigger than 2 characters
  if (w.length() > 1) {
    s.insert(w);
  }
  
  // Return the final set
  return s;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
