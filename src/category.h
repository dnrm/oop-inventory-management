#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>

#include "product.h"

// * ============================
// * Category Class Declaration
// * ============================

class Category {
   private:
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
    // Setters
    void setCategoryID(int id);
};

#endif