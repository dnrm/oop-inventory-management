#include "product.h"

// Constructor
Product::Product(std::string name, double price, int availableQuantity,
                 Supplier* supplier, Category* category, int productID)
    : name(name),
      price(price),
      availableQuantity(availableQuantity),
      supplier(supplier),
      category(category),
      productID(productID) {}

// Getters
std::string Product::getName() { return name; }

double Product::getPrice() { return price; }

int Product::getAvailableQuantity() { return availableQuantity; }

Supplier* Product::getSupplier() { return supplier; }

Category* Product::getCategory() { return category; }

int Product::getProductID() { return productID; }

// Actions
void Product::registerPurchase(int quantity) {
    std::cout << "Registering purchase..." << std::endl;

    if (quantity > availableQuantity) {
        std::cout << "would you like to order " << quantity - availableQuantity
                  << " more? (y/n): ";
        std::string answer;
        std::getline(std::cin, answer);

        if (answer == "y") {
            orderMoreStock(quantity - availableQuantity);
            std::cout << "\nPurchase successful." << std::endl;
            availableQuantity -= quantity;
        } else {
            std::cout << "\nPurchase cancelled." << std::endl;
        }
    } else {
        std::cout << "\nPurchase successful." << std::endl;
        availableQuantity -= quantity;
    }
}

void Product::orderMoreStock(int quantity) { availableQuantity += quantity; }

// Coffee Bag
CoffeeBag::CoffeeBag(std::string name, double price, int availableQuantity,
                     Supplier* supplier, int capacity, Category* category,
                     int productID, double weight, std::string grindType)
    : Product(name, price, availableQuantity, supplier, category, productID),
      weight(weight),
      grindType(grindType) {}

double CoffeeBag::getWeight() { return weight; }

std::string CoffeeBag::getGrindType() { return grindType; }

// Cup
Cup::Cup(std::string name, double price, int availableQuantity,
         Supplier* supplier, int capacity, Category* category, int productID,
         std::string material)
    : Product(name, price, availableQuantity, supplier, category, productID),
      material(material) {}

std::string Cup::getMaterial() { return material; }