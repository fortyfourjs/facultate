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

    int getItemLevel() const
    {
        return item_level;
    }

~Item()
{
    delete[] item_name;
}

};

class Weapon : public Item
{
    public:
        Weapon(const char* item_name, int quantity = 0, int item_level = 0)
            : Item(item_name, quantity, item_level){}
        
        virtual void display() const
        {
            cout << "---Weapon---\n";
            Item::display();
        }
};

class Armor : public Item
{
    public:
        Armor(const char* item_name, int quantity = 0, int item_level = 0)
            : Item(item_name, quantity, item_level){}
        
        virtual void display() const
        {
            cout << "---Armor---\n";
            Item::display();
        }
};

class Inventory
{
    private:
        vector<Item> items;
        int capacity;
        vector<int> itemLevels;

    public:
        Inventory(int capacity) : capacity(capacity)
        {
            items.reserve(capacity);
            itemLevels.reserve(capacity);
        }

    void addItem(const Item* newItem)
    {
        if(newItem != nullptr)
        {
        items.push_back(*newItem);
        itemLevels.push_back(newItem->getItemLevel());
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

     void displayItemLevels() const
    {
        cout << "Item levels: \n";
        for(const auto& level : itemLevels)
        {
            cout << level << '\n';
        }
    }

    vector<int>& getItemLevels() 
    {
        return itemLevels;
    }

};

int partition(int itemLevels[], int low, int high)
{
    int pivot = itemLevels[high];
    int i = (low - 1);

    for(int j = low; j <= high; j++)
    {
        if(itemLevels[j] < pivot)
        {
            i++;
            swap(itemLevels[i],itemLevels[j]);
        }
    }
    swap(itemLevels[i+1],itemLevels[high]);
    return (i+1);

}

void quickSort(int itemLevels[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(itemLevels, low, high);

        quickSort(itemLevels, low, pi - 1);
        quickSort(itemLevels, pi + 1, high);
    }
}


int main()
{
  Inventory bags(10);
  Item item1("Frostmourne", 1, 69);
  bags.addItem(&item1);
  Item item2("Chaotic-Axe", 1, 75);
  bags.addItem(&item2);
  Item item3("Shattering-Katana", 1, 80);
  Item item4("Howling Abyss", 1, 35);
  Item item5("idontknow", 1, 98);
  Item item6("whoknows", 1, 72);
  bags.addItem(&item3);
  bags.addItem(&item4);
  bags.addItem(&item5);
  bags.addItem(&item6);
  bags.displayInventory();  
  bags.displayItemLevels();
  cout << '\n';

  cout << "Before sorting ";
  bags.displayItemLevels();
  cout << '\n';

  vector<int>& levels = bags.getItemLevels();
  quickSort(levels.data(), 0, levels.size() - 1);

  cout << "After sorting ";
  bags.displayItemLevels();
  cout << '\n';
 




    return 0;

}
