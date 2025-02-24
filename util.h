#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
#include <iterator>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

  // Generic template for comparing intersection between a set of any type

  // Create a standard set to store the variables
  std::set<T> s;

  // This first for loop iterates through every element of set 1
  for(typename std::set<T>::iterator i = s1.begin(); i != s1.end(); i ++) {
    
    // Use find to see if there is a similar element
    typename std::set<T>::iterator j = s2.find(*i);
    
    // If there is a unique element, add it to the intersection list
    if (j != s2.end()){
      s.insert(*i);

    }
  }

  // Return the list at the end
  return s;
}


// Set Union Code
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

  // Generic template for comparing 2 sets to create a new set that has all of the elememts combined in the sets
  // Create a standard set to store the variables
  std::set<T> s;

  // This first for loop iterates through every element of set 1
  for (typename std::set<T>::iterator i = s1.begin(); i != s1.end(); i ++) {
    
    // Insert every single element that's in s1
    s.insert(*i);
  }

  // The second loop iterates through every element of set 2 
  for (typename std::set<T>::iterator i = s2.begin(); i != s2.end(); i ++) {
    // Adds all of them, sets automatically do not repeat values
    s.insert(*i);
  }

  // Return the list at the end
  return s;
}




/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
