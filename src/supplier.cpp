#include "supplier.h"

// Generate a unique supplier ID
int generateSupplierID() {
    static int id = 0;
    return id++;
}

// Constructor
Supplier::Supplier(std::string name, std::string contact, std::string address, int supplierID)
    : name(name),
      contact(contact),
      address(address),
      supplierID(supplierID) {}

// Getters
std::string Supplier::getName() { return name; }

std::string Supplier::getContact() { return contact; }

std::string Supplier::getAddress() { return address; }

int Supplier::getSupplierID() { return supplierID; }