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

void testRemoveProduct() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address", 1);
    Category category("Test Category", "Test Description", 1);
    Product product("Test Product", 10.0, 100, &supplier, &category, 1);

    inventory.addProduct(&product);
    inventory.removeProduct(1);

    if (inventory.getAllProducts().size() == 0) {
        std::cout << "✅ testRemoveProduct passed." << std::endl;
    } else {
        std::cout << "❌ testRemoveProduct failed." << std::endl;
    }
}

void testRemoveCategory() {
    Inventory inventory = Inventory();
    Category category("Test Category", "Test Description", 1);

    inventory.addCategory(&category);
    inventory.removeCategory(1);

    if (inventory.getAllCategories().size() == 0) {
        std::cout << "✅ testRemoveCategory passed." << std::endl;
    } else {
        std::cout << "❌ testRemoveCategory failed." << std::endl;
    }
}

void testRemoveSupplier() {
    Inventory inventory = Inventory();
    Supplier supplier("Test Supplier", "123456789", "Test Address", 1);

    inventory.addSupplier(&supplier);
    inventory.removeSupplier(1);

    if (inventory.getAllSuppliers().size() == 0) {
        std::cout << "✅ testRemoveSupplier passed." << std::endl;
    } else {
        std::cout << "❌ testRemoveSupplier failed." << std::endl;
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