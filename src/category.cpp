#include "category.h"

// * ============================
// * Category Class Implementation
// * ============================

// Constructor
Category::Category(std::string name, std::string description)
    : name(name), description(description), categoryID(-1) {}

// Getters
std::string Category::getName() { return name; }

std::string Category::getDescription() { return description; }

int Category::getCategoryID() { return categoryID; }

void Category::setCategoryID(int id) { categoryID = id; }