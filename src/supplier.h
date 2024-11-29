#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream>
#include <string>

class Supplier {
   protected:
    std::string name;
    std::string contact;
    std::string address;
    int supplierID;

   public:
    Supplier(std::string name, std::string contact, std::string address);
    // Getters
    std::string getName();
    std::string getContact();
    std::string getAddress();
    int getSupplierID();
    // Setters
    void setSupplierID(int supplierID);
};

#endif