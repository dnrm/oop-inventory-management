#include <iostream>
#include <string>
#include <vector>

#include "src/category.h"
#include "src/inventory.h"
#include "src/product.h"
#include "src/supplier.h"

void printProducts(std::vector<Product*> products) {
    printf("\n========== Products ==========\n\n");
    for (Product* product : products) {
        std::cout << product->getName() << "\tPrice: $" << product->getPrice()
                  << "\tQuantity: " << product->getAvailableQuantity()
                  << "\tSupplier: " << product->getSupplier()->getName()
                  << "\tCategory: " << product->getCategory()->getName()
                  << "\tCapacity: " << product->getCapacity()
                  << "\tID: " << product->getProductID() << std::endl;
    }
    printf("\n==============================\n");
}

// * Read a string from the user (made to avoid code repetition and to make it
// more concise and readable)
std::string get_string(std::string prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}
// * Same thing as get_string but for integers
int get_int(std::string prompt) {
    int line;
    std::cout << prompt;
    std::cin >> line;
    std::cin.ignore();
    return line;
}

void menu() {
    printf("\n========== Menu ==============\n\n");
    printf("1. Add Product\n");
    printf("2. Add Category\n");
    printf("3. Add Supplier\n");
    printf("4. Remove Product\n");
    printf("5. Remove Category\n");
    printf("6. Remove Supplier\n");
    printf("\n");
    printf("7. List Products\n");
    printf("8. List Categories\n");
    printf("9. List Suppliers\n");
    printf("\n");
    printf("10. Register purchase\n");
    printf("11. Order more stock\n");
    printf("\n");
    printf("12. Exit\n");
    printf("\n==============================\n");
}

int main() {
    // * Instanciate an Inventory class
    Inventory inventory = Inventory();

    // * Add default suppliers and categories

    // * Suppliers
    Supplier supplier1 =
        Supplier("Five Elephant", "123456789", "Schwedter Straße", 1);
    Supplier supplier2 =
        Supplier("The Barn", "987654321", "Schönhauser Allee", 2);
    Supplier supplier3 =
        Supplier("Bonanza Coffee", "123456789", "Adalbertstraße", 3);

    // * Categories
    Category category1 = Category("Coffee", "Coffee beans", 1);
    Category category2 = Category("Tea", "Tea leaves", 2);
    Category category3 = Category("Chocolate", "Chocolate bars", 3);

    // * Add the suppliers and categories to the inventory
    inventory.addSupplier(supplier1);
    inventory.addSupplier(supplier2);
    inventory.addSupplier(supplier3);

    inventory.addCategory(category1);
    inventory.addCategory(category2);
    inventory.addCategory(category3);

    while (true) {
        menu();
        int option = get_int("Option: ");

        // Clear screen
        // std::cout << "\033[2J\033[1;1H";

        switch (option) {
            case 1: {
                // Capture product data
                std::string name = get_string("Name: ");
                double price = (double)get_int("Price: ");
                int availableQuantity = get_int("Available Quantity: ");
                int supplierID = get_int("Supplier ID: ");
                int capacity = get_int("Capacity: ");
                int categoryID = get_int("Category ID: ");

                // Get the supplier and category from the provided IDs
                Supplier supplier = inventory.getSupplier(supplierID);
                Category category = inventory.getCategory(categoryID);

                // Create the product and add it to the inventory
                Product* product = new Product(
                    name, price, availableQuantity, &supplier, capacity,
                    &category, inventory.getAllProducts().size() + 1);
                inventory.addProduct(product);
                break;
            }
            case 2: {
                // Capture category data
                std::string name = get_string("Name: ");
                std::string description = get_string("Description: ");
                int categoryID = get_int("Category ID: ");

                // Create and insert the category
                Category category = Category(name, description, categoryID);
                inventory.addCategory(category);
                break;
            }
            case 3: {
                // Capture supplier data
                std::string name = get_string("Name: ");
                std::string contact = get_string("Contact: ");
                std::string address = get_string("Address: ");
                int supplierID = get_int("Supplier ID: ");

                // Create and insert the supplier
                Supplier supplier =
                    Supplier(name, contact, address, supplierID);
                inventory.addSupplier(supplier);
                break;
            }
            case 4: {
                // Capture the product ID and remove it from the inventory
                int productID = get_int("Product ID: ");
                inventory.removeProduct(productID);
                break;
            }
            case 5: {
                // Capture the category ID and remove it from the inventory
                int categoryID = get_int("Category ID: ");
                inventory.removeCategory(categoryID);
                break;
            }
            case 6: {
                // Capture the supplier ID and remove it from the inventory
                int supplierID = get_int("Supplier ID: ");
                inventory.removeSupplier(supplierID);
                break;
            }
            case 7: {
                // Self explanatory lol
                printProducts(inventory.getAllProducts());
                break;
            }
            case 8: {
                printf("\n========== Categories ==========\n\n");
                for (Category* category : inventory.getAllCategories()) {
                    std::cout << category->getName()
                              << "\tDescription: " << category->getDescription()
                              << "\tID: " << category->getCategoryID()
                              << std::endl;
                }
                printf("\n==============================\n");
                break;
            }
            case 9: {
                printf("\n========== Suppliers ==========\n\n");
                for (Supplier* supplier : inventory.getAllSuppliers()) {
                    std::cout << supplier->getName()
                              << "\tContact: " << supplier->getContact()
                              << "\tAddress: " << supplier->getAddress()
                              << "\tID: " << supplier->getSupplierID()
                              << std::endl;
                }
                printf("\n==============================\n");
                break;
            }
            case 10: {
                // Get the product and register a purchase
                int productID = get_int("Product ID: ");
                int quantity = get_int("Quantity: ");

                // Reduce the stock of the product by the quantity specified
                // (this is done in the product class)
                Product& product = inventory.getProduct(productID);
                product.registerPurchase(quantity);
                std::cout << "Purchase registered" << std::endl;
                break;
            }
            case 11: {
                // Get the product and order more stock
                int productID = get_int("Product ID: ");
                int quantity = get_int("Quantity: ");

                // Increase the stock of the product by the quantity specified
                // (this is also done in the product class)
                Product& product = inventory.getProduct(productID);
                product.orderMoreStock(quantity);
                break;
            }
            case 12: {
                return 0;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    }
}