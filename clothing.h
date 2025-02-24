#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


class Clothing : public Product{

private:
  std::string size_;
  std::string brand_;

public: 
  
  Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand);

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  void dump(std::ostream& os) const;


};

#endif


