#include "supplier.h"

// Generate a unique supplier ID
int generateSupplierID() {
    static int id = 0;
    return id++;
}

// Constructor
Supplier::Supplier(std::string name, std::string contact, std::string address)
    : name(name), contact(contact), address(address), supplierID(-1) {}

// Getters
std::string Supplier::getName() { return name; }

std::string Supplier::getContact() { return contact; }

std::string Supplier::getAddress() { return address; }

int Supplier::getSupplierID() { return supplierID; }

// Setters
void Supplier::setSupplierID(int id) { supplierID = id; }