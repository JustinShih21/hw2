#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


class Book : public Product{

private:
  std::string author_;
  std::string isbn_;

public: 
  
  Book(std::string category, std::string name, double price, int qty, std::string author, std::string isbn);

  

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  void dump(std::ostream& os) const;


};

#endif


