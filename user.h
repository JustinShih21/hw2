#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "product.h"
#include <vector>

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    virtual void dump(std::ostream& os);

    // Additional functions for cart
    
    // Add to cart
    void addToCart(Product* p);
    
    // Display/View Cart
    std::string displayCart() const;

    // Buy the cart
    void buyCart();

    // User getter 
    User* getUser(const std::string& username);


private:
    std::string name_;
    double balance_;
    int type_;
    
    // Cart vector, added on 
    std::vector<Product*> cart_;
};
#endif
