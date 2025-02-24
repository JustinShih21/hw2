#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Movie Constructor
Movie::Movie(std::string category, std::string name, double price, int qty, std::string rating, std::string genre):
  Product(category, name, price, qty),
  genre_(genre),
  rating_(rating)
{

}


// Keywords implementation
std::set<std::string> Movie::keywords() const {

  std::set<std::string> s;

  // Adds the name to the list of keywords
  std::set<std::string> setName = parseStringToWords(convToLower(name_));
  s.insert(setName.begin(), setName.end());
  
  // Adds the author to the keywords
  std::set<std::string> setGenre = parseStringToWords(convToLower(genre_));
  s.insert(setGenre.begin(), setGenre.end());

  return s;
}

// Display product method implementation
std::string Movie::displayString() const {
  
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << price_;
  // Returns a correctly formatted string of the product
  return name_ + 
  "\nGenre: " + genre_ + " Rating: " + rating_ + 
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

}

// Code for putting the correct information in the correct format into the txt file
void Movie::dump(std::ostream& os) const {

  os << "movie" << "\n"
  << name_ << "\n"
  << price_ << "\n"
  << qty_ << "\n"
  << genre_ << "\n"
  << rating_ << std::endl;

}


// 
