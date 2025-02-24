#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Clothing Constructor
Clothing::Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand):
  Product(category, name, price, qty),
  size_(size),
  brand_(brand)
{

}


// Keywords implementation
std::set<std::string> Clothing::keywords() const {

  std::set<std::string> s;

  // Adds the name to the list of keywords
  std::set<std::string> setName = parseStringToWords(convToLower(name_));
  s.insert(setName.begin(), setName.end());
  
  // Adds the author to the keywords
  std::set<std::string> setBrand = parseStringToWords(convToLower(brand_));
  s.insert(setBrand.begin(), setBrand.end());

  return s;
}

// Display product method implementation
std::string Clothing::displayString() const {
  
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << price_;
  // Returns a correctly formatted string of the product
  return name_ + 
  "\nSize: " + size_ + " Brand: " + brand_ + 
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";

}

// Code for putting the correct information in the correct format into the txt file
void Clothing::dump(std::ostream& os) const {

  os << "clothing" << "\n"
  << name_ << "\n"
  << price_ << "\n"
  << qty_ << "\n"
  << size_ << "\n"
  << brand_ << std::endl;

}


// 
