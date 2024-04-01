cmake_minimum_required(VERSION 3.26)
project(M2OEP_cmelisky)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP_cmelisky
        main.cpp
        Product.h
        Product.cpp
        Inventory.cpp
        Inventory.h
        FileTech.cpp
        FileTech.h
        Electronics.cpp
        Electronics.h
        Foodstuffs.cpp
        Foodstuffs.h)
