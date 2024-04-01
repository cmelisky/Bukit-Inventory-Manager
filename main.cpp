
#include "Inventory.h"
#include "Product.h"
#include "FileTech.h"
#include "Electronics.h"
#include "Foodstuffs.h"
#include <iostream>


using namespace std;

void displayMenu() {
    cout << ",-----.          ,--.    ,--.  ,--.                               " << endl;
    cout << "|  |) /_ ,--.,--.|  |,-. `--',-'  '-.                             " << endl;
    cout << "|  .-.  \\|  ||  ||     / ,--.'-.  .-'                             " << endl;
    cout << "|  '--' /'  ''  '|  \\  \\ |  |  |  |                               " << endl;
    cout << "`------'  `----' `--'`--'`--'  `--'                               " << endl;
    cout << ",--.                                ,--.                          " << endl;
    cout << "|  |,--,--,--.  ,--.,---. ,--,--, ,-'  '-. ,---. ,--.--.,--. ,--. " << endl;
    cout << "|  ||      \\  `'  /| .-. :|      \\'-.  .-'| .-. ||  .--' \\  '  /  " << endl;
    cout << "|  ||  ||  |\\    / \\   --.|  ||  |  |  |  ' '-' '|  |     \\   '   " << endl;
    cout << "`--'`--''--' `--'   `----'`--''--'  `--'   `---' `--'   .-'  /    " << endl;
    cout << ",--.   ,--.                                             `---'     " << endl;
    cout << "|   `.'   | ,--,--.,--,--,  ,--,--. ,---.  ,---. ,--.--.          " << endl;
    cout << "|  |'.'|  |' ,-.  ||      \\' ,-.  || .-. || .-. :|  .--'          " << endl;
    cout << "|  |   |  |\\ '-'  ||  ||  |\\ '-'  |' '-' '\\   --.|  |             " << endl;
    cout << "`--'   `--' `--`--'`--''--' `--`--'.`-  /  `----'`--'             " << endl;
    cout << "                                   `---'                          " << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Remove Product" << endl;
    cout << "3. Update Quantity" << endl;
    cout << "4. Display Inventory" << endl;
    cout << "5. Save Inventory" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    /*
     * creating inventory object
     * loading inventory.txt file, creating it if necessary
     */
    Inventory inventory;
    string fname = "inventory.txt";
    FileTech::loadInventory(inventory, fname);

    /*
     * initializing menu display by setting choice to zero
     * and entering the loop, which is only exited by choice 6
     */
    int choice = 0;
    while (choice != 6) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            //add/create product
            string name;
            double price;
            int quantity;
            string type;

            //gets product type (with input validation)
            while (true) {
                cout << "Enter product type (Electronics/Foodstuffs/Other): ";
                if (cin >> type) {
                    break;
                } else {
                    cout << "Invalid input. Please enter a valid product type." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            /*
             * this loop adds products to the product vector
             * and allows the user to input all required variable names
             */
            if (type == "Other" || type == "Electronics" || type == "Foodstuffs") {
                //gets product name (with input validation)
                while (true) {
                    cout << "Enter product name: ";
                    if (cin >> name) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid product name." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                //gets price (with input validation)
                while (true) {
                    cout << "Enter price: ";
                    if (cin >> price) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid price." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                //gets quantity (with input validation)
                while (true) {
                    cout << "Enter quantity: ";
                    if (cin >> quantity) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid quantity." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }


                //handles type of products
                //electronics constructor
                if (type == "Electronics") {
                    string brand, model;

                    cout << "Enter brand: ";
                    cin.ignore();
                    getline(cin, brand);

                    cout << "Enter model: ";
                    getline(cin, model);

                    Product *product = new Electronics(name, price, quantity, brand, model);
                    inventory.addProduct(product);

                    //foodstuffs constructor
                } else if (type == "Foodstuffs") {
                    string expiryDate;
                    cout << "Enter expiry date: ";
                    cin.ignore();
                    getline(cin, expiryDate);

                    Product *product = new Foodstuffs(name, price, quantity, expiryDate);
                    inventory.addProduct(product);

                    //default product constructor
                } else if (type == "Other") {
                    Product *product = new Product(name, price, quantity);
                    inventory.addProduct(product);
                }

                cout << "Product added successfully!" << endl;

            } else {
                cout << "Invalid input. Please enter a valid product type." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (choice == 2) {
            //removes product
            string productName;
            cout << "Enter product name to remove: ";
            getline(cin, productName);
            inventory.removeProduct(productName);
            choice = 0;

        } else if (choice == 3) {
            //updates product quantity
            string productName;
            int newQuantity;
            cout << "Enter product name to update quantity: ";
            getline(cin, productName);
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            inventory.updateQuantity(productName, newQuantity);
            choice = 0;

        } else if (choice == 4) {
            //displays inventory
            inventory.displayInventory();

        } else if (choice == 5) {
            //saves inventory using file handler
            FileTech::saveInventory(inventory, fname);

        } else if (choice == 6) {
            //quits program
            cout << "Exiting program..." << endl;
            return 0;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
