#include "user.h"
#include "product.h"
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ = std::round((balance_ - amt) * 100 / 100);
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << std::fixed << std::setprecision(2) << balance_ << " " << type_ << endl;
}

// Add to cart
void User::addToCart(Product* p) {

  // Add the product to the cart vector
  cart_.push_back(p);

}
    
// Display/View Cart
std::string User::displayCart() const {

  std::string s;
  int count = 0;

  // For every product in the cart, create a line that says #. "product name"
  for(Product* p : cart_){  
    s += std::to_string(count) + ". " + p->getName() + "\n";
    count++;
  }

  // Return the string 
  return s;

}

void User::buyCart() {
    std::vector<Product*> remainingCart;

    for (size_t i = 0; i < cart_.size(); i++) {
        Product* p = cart_[i];

        // Check to see if it's in stock
        if (p->getQty() > 0) {
            // If the user has enough money in the account
            if (balance_ >= p->getPrice()) {
                balance_ -= p->getPrice();  
                p->subtractQty(1);          
            } 
            else {
                // Keep items that couldn't be purchased
                remainingCart.push_back(p);
            }
        } 
        
        
    }

    // Update cart with only items that weren't purchased
    cart_ = remainingCart;
}



