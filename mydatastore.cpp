#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
#include "mydatastore.h"
#include <map>

using namespace std;

// Empty Constructor
MyDataStore::MyDataStore() 
{

}

// De-constrctor
MyDataStore::~MyDataStore() {\

  //std::cout << "Destructor Called" << std::endl;

  //std::cout << "Deleting Called" << std::endl;

  for (size_t i= 0; i < products_.size(); i++) {
    if (products_[i] != nullptr) {
      std::cout << "Deleting Called" << products_[i]->getName() << std::endl;
      delete products_[i];
      products_[i] = nullptr;

    }

  }

  products_.clear();

  // Delete all of the users
  for (std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
    delete it->second;
  }
  users_.clear();
  keysToProducts_.clear();

}

// Method for adding products
void MyDataStore::addProduct(Product* p) {

  // Add the product to the products_ vector
  products_.push_back(p);

  // Add the product keywords to the map 
  std::set<std::string> keys = p->keywords();

  // Loop iterates through every key in keys
  for (const std::string& k : keys) {
    
    // Puts the respective key into the map if not already there
    // Adds the product under the key
    // If the key is there already, it adds the new product to that key
    keysToProducts_[k].insert(p);
  }

}

// Method for adding users
void MyDataStore::addUser(User* u) {

  std::string lowerName = convToLower(u->getName());
  // Add the user to the user_ vector
  users_[lowerName] = u;

}

// Method for searching for products
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  // Clear newHits so you can use it again
  newHits_.clear();

  if (terms.empty()) {

    return {};
  }

  // Make a set to hold all of the key products to return
  std::set<Product*> keyProducts;

  // Goes through all of the terms in terms
  for (size_t i = 0; i < terms.size(); i++) {

    std::string lowT = convToLower(terms[i]);
    std::map<std::string, std::set<Product*>>::iterator it = keysToProducts_.find(lowT);
    // If the term exists in the keyword map
    if (it != keysToProducts_.end()) {

      // Set for products keywords to compare to the terms
      // Make it the list of products matching the key

      std::set<Product*> matchingProducts = keysToProducts_.at(lowT);

      // If the user command is AND
      if (type == 0) {
        
        // Corner case for if the key product set is empty
        if (keyProducts.empty()) {
          keyProducts = matchingProducts;
        }
        else {

          // Creates an intersection set of the key product and matching product set
          keyProducts = setIntersection(keyProducts, matchingProducts);
        }
      }

      // If the user command is OR
      else {

        if (keyProducts.empty()) {
          keyProducts = matchingProducts;
        }
        else {// Creates a union of the key product and matching set
          keyProducts = setUnion(keyProducts, matchingProducts);
        }
      }

    }
  }

  
  // Add all the elements from the set in 
  newHits_.assign(keyProducts.begin(), keyProducts.end());
  
  return newHits_;

}


void MyDataStore::dump(std::ostream& ofile) {

  ofile << "<products>" << std::endl;
  
  // Go through all the products and dump
  for (Product* p : products_) {
    p->dump(ofile);
  }

  ofile << "</products>" << std::endl;

  ofile << "<users>" << std::endl;

  // Go through all of the users and dump
  for (std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
    it->second->dump(ofile);
  }

  ofile << "</users>" << std::endl;
  
}



const std::map<std::string, std::set<Product*>>& MyDataStore::getKeysToProducts() const {
    return keysToProducts_;
}

// Add cart in mydatastore
void MyDataStore::addToCart(const std::string& username, int hit) {

  std::string lowerName = convToLower(username);
  // Corner Case 
  if (users_.count(lowerName) == 0|| (unsigned int) hit > newHits_.size() || hit < 1) {

    // If the username does not exist, or hit is out of range
    std::cout << "Invalid username" << std::endl;
    return;
  }

  // Create a dereferenced pointer to add to the cart
  Product* addedProduct = newHits_[hit - 1];

  // Retrieve the cart
  std::vector<Product*>& userCart = carts_[lowerName];

  // Add the item to the specific user cart
  userCart.push_back(addedProduct);
}

void MyDataStore::viewCart(const std::string& username) {
  std::string lowerName = convToLower(username);
  // Corner Case 
  if (users_.count(lowerName) == 0) {

    // If the username does not exist
    std::cout << "Invalid username" << std::endl;
    return;
  }

  // Retrieve the specific user cart
  vector<Product*>& userCart = carts_[lowerName];

  // For every product in the users cart, display it and its item number
  for (size_t i = 0; i < userCart.size(); i ++) {

    std::cout << "Item " << (i + 1) << std::endl;
    std::cout << userCart[i]->displayString() << std::endl;
    std::cout << endl;


  }

}

void MyDataStore::buyCart(const std::string& username) {
  
  std::string lowerName = convToLower(username);
  // Corner Case 
  if (users_.count(lowerName) == 0) {

    // If the username does not exist
    std::cout << "Invalid username" << std::endl;
    return;
  }

  // Retrieve the specific user cart
  vector<Product*>& userCart = carts_[lowerName];
  User* u = users_[username];

  // Create an iterator for the cart
  std::vector<Product*>::iterator it = userCart.begin();

  while (it != userCart.end()) {

    Product* p = *it;
    double price = p->getPrice();
    int qty = p->getQty();
    

    // Check if its in stock and if the user can pay
    if (qty > 0 && u->getBalance() >= price) {

      // Subtract the quantity, price, and remove the item from the cart
      p->subtractQty(1);
      u->deductAmount(price);
      it = userCart.erase(it);
    }
    // Move to the next item if the product does not meet the requirements
    else {
      it ++;
    }
  }
}
