
#include "Foodstuffs.h"
#include <iostream>

Foodstuffs::Foodstuffs(const std::string& name, double price, int quantity, const std::string& expDate)
        : Product(name, price, quantity), expDate(expDate) {}

const std::string& Foodstuffs::getExpDate() const {
    return expDate;
}

void Foodstuffs::setExpDate(const std::string& expDate) {
    this->expDate = expDate;
}

void Foodstuffs::display() const {
    std::cout << "Name: " << getName() << "\nPrice: " << getPrice() << "\nQuantity: " << getQuantity()
              << "\nExpiration Date: " << expDate << "\n" << std::endl;
}