
#include "Product.h"
#include <iostream>

Product::Product(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string& newName) {
    name = newName;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Product::display() const {
    std::cout << "Name: " << name << "\nPrice: $" << price << "\nQuantity: " << quantity << "\n" << std::endl;
}
