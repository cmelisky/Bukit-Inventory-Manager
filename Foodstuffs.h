
#ifndef M2OEP_CMELISKY_FOODSTUFFS_H
#define M2OEP_CMELISKY_FOODSTUFFS_H

#include "Product.h"
#include <string>

class Foodstuffs : public Product{
private:
    std::string expDate;

public:
    Foodstuffs(const std::string& name, double price, int quantity, const std::string& expDate);

    const std::string& getExpDate() const;
    void setExpDate(const std::string& expDate);

    void display() const override;
};


#endif //M2OEP_CMELISKY_FOODSTUFFS_H
