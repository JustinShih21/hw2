#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "book.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Book Constructor
Book::Book(std::string category, std::string name, double price, int qty, std::string author, std::string isbn):
  Product(category, name, price, qty),
  author_(author),
  isbn_(isbn)
{

}


// Keywords implementation
std::set<std::string> Book::keywords() const {

  std::set<std::string> s;

  // Adds the name to the list of keywords
  std::set<std::string> setName = parseStringToWords(convToLower(name_));
  s.insert(setName.begin(), setName.end());
  
  // Adds the author to the keywords
  std::set<std::string> setAuthor = parseStringToWords(convToLower(author_));
  s.insert(setAuthor.begin(), setAuthor.end());

  // Adds the isbn number to the list of keywords
  s.insert(isbn_);

  return s;
}

// Display product method implementation
std::string Book::displayString() const {
  
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << price_;

  // Returns a correctly formatted string of the product
  return name_ + 
  "\nAuthor: " + author_ + " ISBN: " + isbn_ + 
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

}

// Code for putting the correct information in the correct format into the txt file
void Book::dump(std::ostream& os) const {



  os << "book" << "\n"
  << name_ << "\n"
  << price_ << "\n"
  << qty_ << "\n"
  << isbn_ << "\n"
  << author_ << std::endl;

}


// 
