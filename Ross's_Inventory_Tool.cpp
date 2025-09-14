/*
    Program Name: Ross's Simple Inventory Tool
    Author Name: Ross Baker
    Purpose: Simple CLI Inventory Tool
    Project Timeline: August 2nd, 2025 -> Present
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Item 
{
    string name;        // What is the item called?
    string location;    // Where is it stored?
    int quantity;       // And how many do we have?
};

// Function to show the menu options to the user
void showMenu() 
{
    cout << "\n------ Ross's Simple Inventory Menu! ------\n";
    cout << "\t 1) Add new item\n";
    cout << "\t 2) Display Iventory\n";
    cout << "\t 3) Search for item\n";
    cout << "\t 4) Save to file\n";
    cout << "\t 5) Exit without saving\n";
    cout << "Enter your choice (1 - 5): ";
}

// Function to add a new item to our inventory
void addItem(vector<Item>& inventory) 
{
    Item newItem;  // Create a new empty item
    
    cout << "Enter item name: ";
    getline(cin, newItem.name);
    
    cout << "Enter location: ";
    getline(cin, newItem.location);
    
    cout << "Enter quantity: ";
    cin >> newItem.quantity;
    cin.ignore();
    
    inventory.push_back(newItem); // Add item to inventory vector
    cout << "Item added!\n";
}

// Function to display all items in the inventory
void showAllItems(const vector<Item>& inventory)
{
    if (inventory.empty()) 
    {  // Check if we have no items
        cout << "No items in inventory.\n";
        return;
    }

    cout << "\n--- Current Inventory ---\n";
    for (int i = 0; i < inventory.size(); i++) 
    {
        cout << (i + 1) << ". " << inventory[i].name 
             << " | Location: " << inventory[i].location
             << " | Quantity: " << inventory[i].quantity << "\n";
    }
}

// Function to search for items by name
void searchItems(const vector<Item>& inventory) 
{
    string searchTerm;
    cout << "Enter item name to search: ";
    getline(cin, searchTerm);
    
    bool found = false;
    
    cout << "\n--- Search Results ---\n";
    for (int i = 0; i < inventory.size(); i++) 
    {
        // Check if the search term is contained in the item name
        if (inventory[i].name.find(searchTerm) != string::npos) 
        {
            cout << inventory[i].name 
                 << " | Location: " << inventory[i].location
                 << " | Quantity: " << inventory[i].quantity << "\n";
            found = true;
        }
    }
    
    if (!found) 
    {
        cout << "Search returned no match '" << searchTerm << "'\n";
    }
}

// Function to save inventory to a CSV file
void saveToFile(const vector<Item>& inventory) 
{
    ofstream file("inventory.csv");
    
    // Check if the file opened successfully
    if (!file) 
    {
        cout << "Error: Could not create file!\n";
        return;
    }
    
    // Write the header row (column names)
    file << "Name,Location,Quantity\n";
    
    // Write each item on its own line
    for (int i = 0; i < inventory.size(); i++) 
    {
        file << inventory[i].name << ","
             << inventory[i].location << ","
             << inventory[i].quantity << "\n";
    }
    
    file.close();  // Close the file when we're done
    cout << "Inventory saved to 'inventory.csv!'\n";
}

int main() 
{
    // Make a vector of item structs, which will be our inventory
    vector<Item> inventory;
    int choice;
    
    cout << "Ross's Simple Inventory Tool!\n";
    
    while (true) 
    {
        showMenu();
        cin >> choice;
        cin.ignore();  // Clear the newline character after reading the number
        
        switch (choice) 
        {
            case 1:
                addItem(inventory);
                break;
            case 2:
                showAllItems(inventory);
                break;
            case 3:
                searchItems(inventory);
                break;
            case 4:
                saveToFile(inventory);
                break;
            case 5:
                cout << "Thank you for using Ross's Simple Inventory Tool!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter 1-5.\n";
        }
    }
    
    return 0;
}