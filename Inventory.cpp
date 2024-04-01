
#include "Inventory.h"
#include "Electronics.h"
#include "Foodstuffs.h"
#include <iostream>

void Inventory::addProduct(Product* product) {
    products.push_back(product);
}

void Inventory::displayInventory() const {
    std::cout << "\nInventory:" << std::endl;
    for (const auto& product : products) {
        // Display common attributes for all products
        std::cout << "Name: " << product->getName() << "\n";
        std::cout << "Price: " << product->getPrice() << "\n";
        std::cout << "Quantity: " << product->getQuantity() << "\n";

        // Check the type of product and display specific attributes accordingly
        if (auto* electronicsProduct = dynamic_cast<Electronics*>(product)) {
            std::cout << "Brand: " << electronicsProduct->getBrand() << "\n";
            std::cout << "Model: " << electronicsProduct->getModel() << std::endl;
        } else if (auto* foodstuffsProduct = dynamic_cast<Foodstuffs*>(product)) {
            std::cout << "Expiry date: " << foodstuffsProduct->getExpDate() << std::endl;
        }
    }
}

void Inventory::removeProduct(const std::string& productName) {
    for (auto iTory = products.begin(); iTory != products.end(); iTory++) {
        if ((*iTory)->getName() == productName) {
            delete *iTory;
            products.erase(iTory);
            std::cout << "Product " << productName << " removed successfully." << std::endl;
            return;
        }
    }

    std::cout << "Product " << productName << " not found." << std::endl;
}

void Inventory::updateQuantity(const std::string& name, int newQuantity) {
    for (auto& product : products) {
        if (product->getName() == name) {
            product->setQuantity(newQuantity);
            std::cout << "Quantity for " << name << " updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Product " << name << " not found." << std::endl;
}
