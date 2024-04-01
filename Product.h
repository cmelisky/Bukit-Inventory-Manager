
#ifndef M2OEP_CMELISKY_PRODUCT_H
#define M2OEP_CMELISKY_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    Product(const std::string& name, double price, int quantity);

    std::string getName() const;
    void setName(const std::string& newName);
    double getPrice() const;
    void setPrice(double newPrice);
    int getQuantity() const;
    void setQuantity(int newQuantity);
    virtual void display() const;

};

#endif //M2OEP_CMELISKY_PRODUCT_H
