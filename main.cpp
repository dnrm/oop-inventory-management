#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <sstream>

#include "src/category.h"
#include "src/product.h"
#include "src/supplier.h"
#include "src/inventory.h"

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

void mainMenu() {
    printf("\n========== Menu ==============\n\n");
    printf("1. View\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Stock Management\n");
    printf("\n");
    printf("0. Exit\n");
    printf("\n==============================\n");
}

void addMenu() {
    printf("\n========== Add ==============\n\n");
    printf("1. Add Product\n");
    printf("2. Add Category\n");
    printf("3. Add Supplier\n");
    printf("\n");
    printf("0. Back\n");
    printf("\n==============================\n");
}

void deleteMenu() {
    printf("\n========== Delete ==============\n\n");
    printf("1. Delete Product\n");
    printf("2. Delete Category\n");
    printf("3. Delete Supplier\n");
    printf("\n");
    printf("0. Back\n");
    printf("\n==============================\n");
}

void stockManagementMenu() {
    printf("\n========== Stock Management ==============\n\n");
    printf("1. Register purchase\n");
    printf("2. Order more stock\n");
    printf("\n");
    printf("0. Back\n");
    printf("\n==============================\n");
}

std::string get_string(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

int get_int(const std::string& prompt) {
    std::string line;
    int value;
    std::cout << prompt;
    std::getline(std::cin, line);
    std::stringstream(line) >> value;
    return value;
}

double get_double(const std::string& prompt) {
    std::string line;
    double value;
    std::cout << prompt;
    std::getline(std::cin, line);
    std::stringstream(line) >> value;
    return value;
}

int main() {
    // Instantiate an Inventory class
    Inventory inventory;

    // Default categories and suppliers
    // This is done so that the coffee shop can get straight away to adding their products :)

    Category* category1 = new Category("Coffee Bags", "Bags of whole bean or ground coffee.", 1);
    Category* category2 = new Category("Machines", "Coffee machines for brewing coffee.", 2);
    Category* category3 = new Category("Cups", "Beautiful drinkware for the best coffee.", 3);

    Supplier* supplier1 = new Supplier("Five Elephant Coffee", "1234567890", "Schwedter Straße", 1);
    Supplier* supplier2 = new Supplier("The Barn", "0987654321", "Schönhauser Allee", 2);
    Supplier* supplier3 = new Supplier("Bonanza Coffee", "1234567890", "Adalbertstraße", 3);

    inventory.addCategory(category1);
    inventory.addCategory(category2);
    inventory.addCategory(category3);

    inventory.addSupplier(supplier1);
    inventory.addSupplier(supplier2);
    inventory.addSupplier(supplier3);

    // Define a map to store menu options and corresponding actions
    std::map<int, std::function<void()>> mainActions;
    std::map<int, std::function<void()>> addActions;
    std::map<int, std::function<void()>> deleteActions;
    std::map<int, std::function<void()>> stockManagementActions;

    // Add actions to the main menu map
    mainActions[1] = [&]() {
        printProducts(inventory.getAllProducts());
    };

    mainActions[2] = [&]() {
        while (true) {
            addMenu();
            int option = get_int("Option: ");
            if (option == 0) break;
            auto it = addActions.find(option);
            if (it != addActions.end()) {
                it->second();
            } else {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    };

    mainActions[3] = [&]() {
        while (true) {
            deleteMenu();
            int option = get_int("Option: ");
            if (option == 0) break;
            auto it = deleteActions.find(option);
            if (it != deleteActions.end()) {
                it->second();
            } else {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    };

    mainActions[4] = [&]() {
        while (true) {
            stockManagementMenu();
            int option = get_int("Option: ");
            if (option == 0) break;
            auto it = stockManagementActions.find(option);
            if (it != stockManagementActions.end()) {
                it->second();
            } else {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    };

    // Add actions to the add menu map
    addActions[1] = [&]() {
        std::string name = get_string("Name: ");
        double price = get_double("Price: ");
        int availableQuantity = get_int("Available Quantity: ");
        int supplierID = get_int("Supplier ID: ");
        int categoryID = get_int("Category ID: ");

        // Add the product to the inventory
        Supplier* supplier = &inventory.getSupplier(supplierID);
        Category* category = &inventory.getCategory(categoryID);
        Product* product = new Product(name, price, availableQuantity, supplier, category, inventory.getAllProducts().size() + 1);
        inventory.addProduct(product);
    };

    addActions[2] = [&]() {
        std::string name = get_string("Name: ");
        std::string description = get_string("Description: ");
        int categoryID = get_int("Category ID: ");

        // Create and insert the category
        Category* category = new Category(name, description, categoryID);
        inventory.addCategory(category);
    };

    addActions[3] = [&]() {
        std::string name = get_string("Name: ");
        std::string contact = get_string("Contact: ");
        std::string address = get_string("Address: ");
        int supplierID = get_int("Supplier ID: ");

        // Create and insert the supplier
        Supplier* supplier = new Supplier(name, contact, address, supplierID);
        inventory.addSupplier(supplier);
    };

    // Add actions to the delete menu map
    deleteActions[1] = [&]() {
        int productID = get_int("Product ID: ");
        inventory.removeProduct(productID);
    };

    deleteActions[2] = [&]() {
        int categoryID = get_int("Category ID: ");
        inventory.removeCategory(categoryID);
    };

    deleteActions[3] = [&]() {
        int supplierID = get_int("Supplier ID: ");
        inventory.removeSupplier(supplierID);
    };

    // Add actions to the stock management menu map
    stockManagementActions[1] = [&]() {
        int productID = get_int("Product ID: ");
        int quantity = get_int("Quantity: ");

        try {
            Product& product = inventory.getProduct(productID);
            product.registerPurchase(quantity);
            std::cout << "Purchase registered successfully." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    };

    stockManagementActions[2] = [&]() {
        int productID = get_int("Product ID: ");
        int quantity = get_int("Quantity: ");

        try {
            Product& product = inventory.getProduct(productID);
            product.orderMoreStock(quantity);
            std::cout << "Stock ordered successfully." << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    };

    while (true) {
        mainMenu();
        int option = get_int("Select an option: ");

        if (option == 0) {
            break;
        }

        // Clear the screen
        std::cout << "\033[2J\033[1;1H";

        auto it = mainActions.find(option);
        if (it != mainActions.end()) {
            it->second();
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}