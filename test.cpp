#include <iostream>

#include "src/category.h"
#include "src/inventory.h"
#include "src/product.h"
#include "src/supplier.h"

void testAddProduct() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address", 1);
    Category category("Test Category", "Test Description", 1);
    Product product("Test Product", 10.0, 100, &supplier, &category, 1);

    inventory.addProduct(&product);

    if (inventory.getAllProducts().size() == 1) {
        std::cout << "✅ testAddProduct passed." << std::endl;
    } else {
        std::cout << "❌ testAddProduct failed." << std::endl;
    }
}

void testAddCategory() {
    Inventory inventory = Inventory();
    Category category("Test Category", "Test Description", 1);

    inventory.addCategory(&category);

    if (inventory.getAllCategories().size() == 1) {
        std::cout << "✅ testAddCategory passed." << std::endl;
    } else {
        std::cout << "❌ testAddCategory failed." << std::endl;
    }
}

void testAddSupplier() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address", 1);

    inventory.addSupplier(&supplier);

    if (inventory.getAllSuppliers().size() == 1) {
        std::cout << "✅ testAddSupplier passed." << std::endl;
    } else {
        std::cout << "❌ testAddSupplier failed." << std::endl;
    }
}

int main() {
    testAddProduct();
    testAddCategory();
    testAddSupplier();
    testRemoveProduct();
    testRemoveCategory();
    testRemoveSupplier();
    return 0;
}