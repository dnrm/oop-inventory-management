#include "inventory.h"

// * ============================
// * Inventory Class Implementation
// * ============================

// Constructor
Inventory::Inventory() {}

// Getters
std::vector<Product*> Inventory::getAllProducts() { return products; }
std::vector<Category*> Inventory::getAllCategories() { return categories; }
std::vector<Supplier*> Inventory::getAllSuppliers() { return suppliers; }

// Get a product by filtering the products vector.
Product& Inventory::getProduct(int productID) {
    for (auto product : products) {
        if (product->getProductID() == productID) {
            return *product;
        }
    }
    throw std::runtime_error("Product not found");
}

// Get a category by filtering the categories vector.
Category& Inventory::getCategory(int categoryID) {
    for (auto category : categories) {
        if (category->getCategoryID() == categoryID) {
            return *category;
        }
    }
    throw std::runtime_error("Category not found");
}

// Get a supplier by filtering the suppliers vector.
Supplier& Inventory::getSupplier(int supplierID) {
    for (auto supplier : suppliers) {
        if (supplier->getSupplierID() == supplierID) {
            return *supplier;
        }
    }
    throw std::runtime_error("Supplier not found");
}

// Methods
void Inventory::addProduct(Product* product) { products.push_back(product); }

// This sets the supplierID to the length + 1 of the suppliers vector.
// It is done so that the indexing starts at 1.
void Inventory::addSupplier(Supplier* supplier) {
    supplier->setSupplierID(suppliers.size() + 1);
    suppliers.push_back(supplier);
}

// This sets the categoryID to the length + 1 of the categories vector.
// Same as the suppliers thing, so that the indexing starts at 1.
void Inventory::addCategory(Category* category) {
    category->setCategoryID(categories.size() + 1);
    categories.push_back(category);
}

// Remove a product by filtering the products vector.
// This is done by comparing the productID of the product to be removed
void Inventory::removeProduct(int productID) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getProductID() == productID) {
            delete *it;
            products.erase(it);
            break;
        }
    }
}

// Remove a category by filtering the categories vector.
void Inventory::removeCategory(int categoryID) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if ((*it)->getCategoryID() == categoryID) {
            delete *it;
            categories.erase(it);
            break;
        }
    }
}

// Again remove
void Inventory::removeSupplier(int supplierID) {
    for (auto it = suppliers.begin(); it != suppliers.end(); ++it) {
        if ((*it)->getSupplierID() == supplierID) {
            delete *it;
            suppliers.erase(it);
            break;
        }
    }
}