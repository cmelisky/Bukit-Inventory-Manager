
#ifndef M2OEP_CMELISKY_ELECTRONICS_H
#define M2OEP_CMELISKY_ELECTRONICS_H

#include "Product.h"
#include <string>

class Electronics : public Product{
private:
    std::string brand;
    std::string model;

public:
    Electronics(const std::string& name, double price, int quantity,
                const std::string& brand, const std::string& model);

    const std::string& getBrand() const;
    void setBrand(const std::string& brand);

    const std::string& getModel() const;
    void setModel(const std::string& model);

    void display() const override;

};


#endif //M2OEP_CMELISKY_ELECTRONICS_H
