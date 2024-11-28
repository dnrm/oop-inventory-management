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
        std::cout << "testAddProduct passed." << std::endl;
    } else {
        std::cout << "testAddProduct failed." << std::endl;
    }
}

int main() {
    testAddProduct();
    return 0;
}