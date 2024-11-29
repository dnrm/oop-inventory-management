#include <iostream>

#include "src/category.h"
#include "src/inventory.h"
#include "src/product.h"
#include "src/supplier.h"

void testAddProduct() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address");
    Category category("Test Category", "Test Description");
    CoffeeBag product("Test Product", 1.0, 1, &supplier, &category, 1, 1.0, "Test Grind Type");

    inventory.addProduct(&product);

    if (inventory.getAllProducts().size() == 1) {
        std::cout << "✅ testAddProduct passed." << std::endl;
    } else {
        std::cout << "❌ testAddProduct failed." << std::endl;
    }
}

void testAddCategory() {
    Inventory inventory = Inventory();
    Category category("Test Category", "Test Description");

    inventory.addCategory(&category);

    if (inventory.getAllCategories().size() == 1) {
        std::cout << "✅ testAddCategory passed." << std::endl;
    } else {
        std::cout << "❌ testAddCategory failed." << std::endl;
    }
}

void testAddSupplier() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address");

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
    return 0;
}