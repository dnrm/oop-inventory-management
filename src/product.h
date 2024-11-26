#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

#include "supplier.h"

class Category;

class Product {
   protected:
    std::string name;
    double price;
    int availableQuantity;
    Supplier* supplier;
    int capacity;
    Category* category;
    int productID;

   public:
    // Constructor
    Product(std::string name, double price, int availableQuantity,
            Supplier* supplier, int capacity, Category* category,
            int productID);

    // Getters
    std::string getName();
    double getPrice();
    int getAvailableQuantity();
    Supplier* getSupplier();
    int getCapacity();
    Category* getCategory();
    int getProductID();

    // Actions
    void registerPurchase(int quantity);
    void orderMoreStock(int quantity);
};

#endif  // PRODUCT_H