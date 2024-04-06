#include <iostream>
#include <cstring>
#include <vector>
#define MAX 40
using namespace std;


class Item
{
private:
    char* item_name;
    int quantity;
    int item_level;
    
public:
    Item(const char* item_name = "", int quantity = 0, int item_level = 0)
    {
        this->item_name = new char[MAX];
        strncpy(this->item_name, item_name, MAX - 1);
        this->item_name[MAX - 1] = '\0';
        this->quantity = quantity;
        this->item_level = item_level;
    }

    Item(const Item& other)
    {
        item_name = new char[MAX];
        strncpy(item_name, other.item_name, MAX);
        quantity = other.quantity;
        item_level = other.item_level;
    }

    Item& operator=(const Item& other)
    {
        if(this != &other)
        {
            char* new_name = new char[MAX];
            strncpy(new_name, other.item_name, MAX);
            delete[] item_name;
            item_name = new_name;
            quantity = other.quantity;
            item_level = other.item_level;
        }
        return *this;
    }
    void display() const
    {

        cout << "Name: " << item_name << '\n';
        cout << "Quantity: " << quantity << '\n';
        cout << "ilvl: " << item_level << '\n';
    }

    char* getItemName()
    {
        return item_name;
    }

    int getQuantity()
    {
        return quantity;
    }

    int getItemLevel()
    {
        return item_level;
    }

~Item()
{
    delete[] item_name;
}

};


class Inventory
{
    private:
        vector<Item> items;
        int capacity;

    public:
        Inventory(int capacity) : capacity(capacity){}

    void addItem(const Item* newItem)
    {
        if(newItem != nullptr)
        {
        items.push_back(*newItem);
        }
    }
    void removeItem(int index)
    {
        if(index >= 0 && index < items.size())
        {
            items.erase(items.begin() + index);
        }
    }
    void displayInventory()
    {
        cout << "capacity: " << capacity << '\n';
        cout << "Items:\n";
        for(const auto& item : items)
        {
            item.display();
            cout << '\n';
        }
    }

};

int main()
{
  Inventory bags(10);
  Item item1("Sword", 5, 69);
  bags.addItem(&item1);
  bags.displayInventory();
  Item item2("Axe", 1, 75);
  bags.addItem(&item2);
  bags.displayInventory();


return 0;
}
