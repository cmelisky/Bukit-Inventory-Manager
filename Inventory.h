
#ifndef M2OEP_CMELISKY_INVENTORY_H
#define M2OEP_CMELISKY_INVENTORY_H

#include "Product.h"
#include <vector>

class Inventory {
private:
    std::vector<Product*> products;
    friend class FileTech;

public:
    void addProduct (Product* Product);
    void displayInventory() const;
    void removeProduct(const std::string& name);
    void updateQuantity(const std::string& name, int newQuantity);
};

#endif //M2OEP_CMELISKY_INVENTORY_H
