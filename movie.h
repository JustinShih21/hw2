#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


class Movie : public Product{

private:
  std::string genre_;
  std::string rating_;

public: 
  
  Movie(std::string category, std::string name, double price, int qty, std::string genre, std::string rating);

  std::set<std::string> keywords() const override;

  std::string displayString() const override;

  void dump(std::ostream& os) const;


};

#endif

