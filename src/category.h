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
    std::vector<Product*> products;

   public:
    // Constructor
    Category(std::string name, std::string description, int categoryID);
    // Getters
    std::string getName();
    std::string getDescription();
    int getCategoryID();
    std::vector<Product*> getProducts();
    // Methods
    void addProduct(Product* product);
};

#endif