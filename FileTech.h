
#ifndef M2OEP_CMELISKY_FILETECH_H
#define M2OEP_CMELISKY_FILETECH_H

#include "Inventory.h"
#include <string>

class FileTech {
public:
    static void saveInventory(const Inventory& inventory, const std::string& fname);
    static void loadInventory(Inventory& inventory, const std::string& fname);
};

#endif //M2OEP_CMELISKY_FILETECH_H
