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

    void display() const
    {
        cout << "---Item---" << '\n';
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
  Item* item1 = new Item("Sword", 5, 69);
  Item copy(*item1);
  Inventory inventory(10);
  inventory.addItem(&copy);
  inventory.displayInventory();
  delete item1;






    return 0;
}
