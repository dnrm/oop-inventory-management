#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

#include "supplier.h"

// * ============================
// * Product Class Declaration
// * ============================

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

    // This is a virtual function because every derived class has different data
    // that must be displayed so yea.
    virtual void displayDetails() = 0;
};

// * ============================
// * Derived Classes
// * ============================

class CoffeeBag : public Product {
   private:
    double weight;
    std::string grindType;

   public:
    // Constructor
    CoffeeBag(std::string name, double price, int availableQuantity,
              Supplier* supplier, Category* category, int productID,
              double weight, std::string grindType);

    // Getters
    double getWeight();
    std::string getGrindType();

    // Actions
    void displayDetails();
};

class Cup : public Product {
   private:
    std::string material;

   public:
    // Constructor
    Cup(std::string name, double price, int availableQuantity,
        Supplier* supplier, Category* category, int productID,
        std::string material);

    // Getters
    std::string getMaterial();

    // Actions
    void displayDetails();
};

class Machine : public Product {
   private:
    std::string type;

   public:
    // Constructor
    Machine(std::string name, double price, int availableQuantity,
            Supplier* supplier, Category* category, int productID,
            std::string type);

    // Getters
    std::string getType();

    // Actions
    void displayDetails();
};

#endif  // PRODUCT_H