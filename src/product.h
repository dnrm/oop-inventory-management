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
    Category* category;
    int productID;

   public:
    // Constructor
    Product(std::string name, double price, int availableQuantity,
            Supplier* supplier, Category* category, int productID);

    // Getters
    std::string getName();
    double getPrice();
    int getAvailableQuantity();
    Supplier* getSupplier();
    Category* getCategory();
    int getProductID();

    // Actions
    void registerPurchase(int quantity);
    void orderMoreStock(int quantity);
};

class CoffeeBag : public Product {
   private:
    double weight;
    std::string grindType;

   public:
    // Constructor
    CoffeeBag(std::string name, double price, int availableQuantity,
              Supplier* supplier, int capacity, Category* category,
              int productID, double weight, std::string grindType);

    // Getters
    double getWeight();
    std::string getGrindType();
};

class Cup : public Product {
   private:
    std::string material;

   public:
    // Constructor
    Cup(std::string name, double price, int availableQuantity,
        Supplier* supplier, int capacity, Category* category, int productID,
        std::string material);

    // Getters
    std::string getMaterial();
};

#endif  // PRODUCT_H