#include "product.h"

#include "category.h"

// * ============================
// * Product Class Implementation
// * ============================

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

    // If there is not enough of a product:
    if (quantity > availableQuantity) {
        std::cout << "would you like to order " << quantity - availableQuantity
                  << " more? (y/n): ";
        std::string answer;
        std::getline(std::cin, answer);

        if (answer == "y") {
            // Order the stock but don't forget to update the availableQuantity
            orderMoreStock(quantity - availableQuantity);
            std::cout << "\nPurchase successful." << std::endl;
            availableQuantity -= quantity;
        } else {
            std::cout << "\nPurchase cancelled." << std::endl;
        }
    } else {
        // If there is enough stock :D
        std::cout << "\nPurchase successful." << std::endl;
        availableQuantity -= quantity;
    }
}

void Product::orderMoreStock(int quantity) { availableQuantity += quantity; }

// * ============================
// * CoffeeBag Class Implementation
// * ============================

// Constructor
CoffeeBag::CoffeeBag(std::string name, double price, int availableQuantity,
                     Supplier* supplier, Category* category, int productID,
                     double weight, std::string grindType)
    : Product(name, price, availableQuantity, supplier, category, productID),
      weight(weight),
      grindType(grindType) {}

// Getters
double CoffeeBag::getWeight() { return weight; }

std::string CoffeeBag::getGrindType() { return grindType; }

// Actions
void CoffeeBag::displayDetails() {
    std::cout << name << "\tPrice: $" << price
              << "\tQuantity: " << availableQuantity
              << "\tSupplier: " << supplier->getName()
              << "\tCategory: " << category->getName() << "\tID: " << productID
              << "\tWeight: " << weight << "\tGrind Type: " << grindType
              << std::endl;
}

// * ============================
// * Cup Class Implementation
// * ============================

// Constructor
Cup::Cup(std::string name, double price, int availableQuantity,
         Supplier* supplier, Category* category, int productID,
         std::string material)
    : Product(name, price, availableQuantity, supplier, category, productID),
      material(material) {}

// Getters
std::string Cup::getMaterial() { return material; }

// Actions
void Cup::displayDetails() {
    std::cout << name << "\tPrice: $" << price
              << "\tQuantity: " << availableQuantity
              << "\tSupplier: " << supplier->getName()
              << "\tCategory: " << category->getName() << "\tID: " << productID
              << "\tMaterial: " << material << std::endl;
}

// * ============================
// * Machine Class Implementation
// * ============================

// Constructor
Machine::Machine(std::string name, double price, int availableQuantity,
                 Supplier* supplier, Category* category, int productID,
                 std::string type)
    : Product(name, price, availableQuantity, supplier, category, productID),
      type(type) {}

// Getters
std::string Machine::getType() { return type; }

// Actions
void Machine::displayDetails() {
    std::cout << name << "\tPrice: $" << price
              << "\tQuantity: " << availableQuantity
              << "\tSupplier: " << supplier->getName()
              << "\tCategory: " << category->getName() << "\tID: " << productID
              << "\tType: " << type << std::endl;
}