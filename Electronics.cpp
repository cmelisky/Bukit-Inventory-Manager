
#include "Electronics.h"
#include <iostream>

Electronics::Electronics(const std::string& name, double price, int quantity,
                         const std::string& brand, const std::string& model)
        : Product(name, price, quantity), brand(brand), model(model) {}

const std::string& Electronics::getBrand() const {
    return brand;
}

void Electronics::setBrand(const std::string& brand) {
    this->brand = brand;
}

const std::string& Electronics::getModel() const {
    return model;
}

void Electronics::setModel(const std::string& model) {
    this->model = model;
}

void Electronics::display() const {
    std::cout << "Name: " << getName() << "\nPrice: " << getPrice() << "\nQuantity: " << getQuantity()
              << "\nBrand: " << brand << "\nModel: " << model << "\n" << std::endl;
}
