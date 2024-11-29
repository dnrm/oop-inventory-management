#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>

#include "product.h"

class Category {
   protected:
    std::string name;
    std::string description;
    int categoryID;

   public:
    // Constructor
    Category(std::string name, std::string description);
    // Getters
    std::string getName();
    std::string getDescription();
    int getCategoryID();
    void setCategoryID(int id);
};

#endif