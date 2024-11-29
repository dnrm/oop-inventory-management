#include "inventory.h"

// Constructor
Inventory::Inventory() {}

// Getters
std::vector<Product*> Inventory::getAllProducts() { return products; }

std::vector<Category*> Inventory::getAllCategories() { return categories; }

std::vector<Supplier*> Inventory::getAllSuppliers() { return suppliers; }

Product& Inventory::getProduct(int productID) {
    for (auto product : products) {
        if (product->getProductID() == productID) {
            return *product;
        }
    }
    throw std::runtime_error("Product not found");
}

Category& Inventory::getCategory(int categoryID) {
    for (auto category : categories) {
        if (category->getCategoryID() == categoryID) {
            return *category;
        }
    }
    throw std::runtime_error("Category not found");
}

Supplier& Inventory::getSupplier(int supplierID) {
    for (auto supplier : suppliers) {
        if (supplier->getSupplierID() == supplierID) {
            return *supplier;
        }
    }
    throw std::runtime_error("Supplier not found");
}

// Methods
void Inventory::addProduct(Product* product) {
    products.push_back(product);
}

void Inventory::addSupplier(Supplier* supplier) {
    supplier->setSupplierID(suppliers.size() + 1);
    suppliers.push_back(supplier);
}

void Inventory::addCategory(Category* category) {
    category->setCategoryID(categories.size() + 1);
    categories.push_back(category);
}

void Inventory::removeProduct(int productID) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getProductID() == productID) {
            delete *it;
            products.erase(it);
            break;
        }
    }
}

void Inventory::removeCategory(int categoryID) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if ((*it)->getCategoryID() == categoryID) {
            delete *it;
            categories.erase(it);
            break;
        }
    }
}

void Inventory::removeSupplier(int supplierID) {
    for (auto it = suppliers.begin(); it != suppliers.end(); ++it) {
        if ((*it)->getSupplierID() == supplierID) {
            delete *it;
            suppliers.erase(it);
            break;
        }
    }
}