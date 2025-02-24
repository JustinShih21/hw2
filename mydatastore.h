#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
#include "map"

class MyDataStore : public DataStore {

private:
  // Create the different vectors to hold users and products
  std::vector<Product*> products_;
  std::map<std::string, User*> users_;

  // Create a map for fast lookups
  std::map<std::string, std::set<Product*>> keysToProducts_;

  std::vector<Product*> newHits_;

  std::map<std::string, std::vector<Product*>> carts_;

public:

  // Constructor and De-Constructor
  MyDataStore();
  ~MyDataStore();

  // Add in all the virtual unwritten methods from datastore.h
  void addProduct(Product* p) override;

  void addUser(User* u);

  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  void dump(std::ostream& ofile);

  void addToCart(const std::string& username, int hit);

  void viewCart(const std::string& username);

  void buyCart(const std::string& username);

  const std::map<std::string, std::set<Product*>>& getKeysToProducts() const;
  

};

#endif

