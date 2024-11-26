#include "category.h"

// Constructor
Category::Category(std::string name, std::string description, int categoryID)
    : name(name), description(description), categoryID(categoryID) {
    products = std::vector<Product*>();
}

// Getters
std::string Category::getName() { return name; }

std::string Category::getDescription() { return description; }

int Category::getCategoryID() { return categoryID; }

std::vector<Product*> Category::getProducts() { return products; }

// Methods
void Category::addProduct(Product* product) { products.push_back(product); }