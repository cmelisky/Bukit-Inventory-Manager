
#include "FileTech.h"
#include "Electronics.h"
#include "Foodstuffs.h"
#include <iostream>
#include <fstream>

void FileTech::saveInventory(const Inventory& inventory, const std::string& fname) {
    std::ofstream file(fname);
    if (file.is_open()) {
        for (const auto& product : inventory.products) {
            file << product->getName() << " " << product->getPrice() << " " << product->getQuantity();

            if (auto* electronicsProduct = dynamic_cast<Electronics*>(product)) {
                file << " " << electronicsProduct->getBrand() << " " << electronicsProduct->getModel();
            } else if (auto* foodstuffsProduct = dynamic_cast<Foodstuffs*>(product)) {
                file << " " << foodstuffsProduct->getExpDate();
            }

            file << std::endl;
        }
        std::cout << "Inventory saved to " << fname << std::endl;
    } else {
        std::cout << "Error: Unable to open file " << fname << ". Please try again." << std::endl;
    }
}

void FileTech::loadInventory(Inventory& inventory, const std::string& fname) {
    std::ifstream file(fname);
    if (file.is_open()) {
        std::string name;
        double price;
        int quantity;
        std::string brand;
        std::string model;
        std::string expDate;

        while (file >> name >> price >> quantity) {
            if (file.peek() == '\n') {
                file.ignore();
            } else if (file.peek() != EOF) {
                if (file.peek() == ' ') {
                    file >> brand >> model;
                } else {
                    file >> expDate;
                }
            }
            if (!brand.empty() && !model.empty()) {
                Product* product = new Electronics(name, price, quantity, brand, model);
                inventory.addProduct(product);
            } else if (!expDate.empty()) {
                Product* product = new Foodstuffs(name, price, quantity, expDate);
                inventory.addProduct(product);
            } else {
                // No additional fields, create a basic Product
                Product* product = new Product(name, price, quantity);
                inventory.addProduct(product);
            }
        }
        std::cout << "Inventory loaded from file: " << fname << std::endl;

    } else if (!file.is_open()) {
        std::cout << "File 'inventory.txt' does not exist. Creating it..." << std::endl;

        std::ofstream outfile(fname);
        if (outfile.is_open()) {
            std::cout << "File 'inventory.txt' created successfully." << std::endl;
            outfile.close();
        } else {
            std::cout << "Error: Unable to create file 'inventory.txt'." << std::endl;
            std::cout << "Program will not be able to use full functionality :(" << std::endl;
        }
    }
}
