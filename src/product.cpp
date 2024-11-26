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
void Product::registerPurchase(int quantity) {
    std::cout << "Registering purchase. Current quantity: " << availableQuantity
              << ", Quantity to reduce: " << quantity << std::endl;
    availableQuantity -= quantity;
    std::cout << "New quantity: " << availableQuantity << std::endl;
}

void Product::orderMoreStock(int quantity) { availableQuantity += quantity; }

// Coffee Bag
CoffeeBag::CoffeeBag(std::string name, double price, int availableQuantity,
                     Supplier* supplier, int capacity, Category* category,
                     int productID, double weight, std::string grindType)
    : Product(name, price, availableQuantity, supplier, capacity, category,
              productID),
      weight(weight),
      grindType(grindType) {}

double CoffeeBag::getWeight() { return weight; }

std::string CoffeeBag::getGrindType() { return grindType; }

// Cup
Cup::Cup(std::string name, double price, int availableQuantity,
         Supplier* supplier, int capacity, Category* category, int productID,
         std::string material)
    : Product(name, price, availableQuantity, supplier, capacity, category,
              productID),
      material(material) {}

std::string Cup::getMaterial() { return material; }