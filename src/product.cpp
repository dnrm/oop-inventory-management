#include "product.h"

// Constructor
Product::Product(std::string name, double price, int availableQuantity,
                 Supplier* supplier, int capacity, Category* category,
                 int productID)
    : name(name),
      price(price),
      availableQuantity(availableQuantity),
      supplier(supplier),
      capacity(capacity),
      category(category),
      productID(productID) {}

// Getters
std::string Product::getName() { return name; }

double Product::getPrice() { return price; }

int Product::getAvailableQuantity() { return availableQuantity; }

Supplier* Product::getSupplier() { return supplier; }

int Product::getCapacity() { return capacity; }

Category* Product::getCategory() { return category; }

int Product::getProductID() { return productID; }

// Actions
void Product::registerPurchase(int quantity) { availableQuantity -= quantity; }

void Product::orderMoreStock(int quantity) { availableQuantity += quantity; }