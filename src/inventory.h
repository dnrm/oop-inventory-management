#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

#include "category.h"
#include "product.h"
#include "supplier.h"

class Inventory {
   protected:
    std::vector<Product*> products;
    std::vector<Category*> categories;
    std::vector<Supplier*> suppliers;

   public:
    // Constructor

    Inventory();

    // Getters

    std::vector<Product*> getAllProducts();
    std::vector<Category*> getAllCategories();
    std::vector<Supplier*> getAllSuppliers();

    Product& getProduct(int productID);
    Category& getCategory(int categoryID);
    Supplier& getSupplier(int supplierID);

    // Methods
    void addProduct(Product* product);
    void addCategory(Category* category);
    void addSupplier(Supplier* supplier);

    void removeProduct(int productID);
    void removeCategory(int categoryID);
    void removeSupplier(int supplierID);
};

#endif