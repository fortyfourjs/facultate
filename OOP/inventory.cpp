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
    int durability;
    int weight;
    
public:
    Item(const char* item_name = "", int quantity = 0, int item_level = 0, int durability = 0, int weight = 0)
    {
        this->item_name = new char[MAX];
        strncpy(this->item_name, item_name, MAX - 1);
        this->quantity = quantity;
        this->item_level = item_level;
        this->durability = durability;
        this->weight = weight;
    }

    Item(const Item& other)
    {
        item_name = new char[MAX];
        strncpy(item_name, other.item_name, MAX);
        quantity = other.quantity;
        item_level = other.item_level;
        durability = other.durability;
        weight = other.weight;
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
            durability = other.durability;
            weight = other.weight;
        }
        return *this;
    }
    virtual void display() const
    {

        cout << "Name: " << item_name << '\n';
        cout << "Quantity: " << quantity << '\n';
        cout << "ilvl: " << item_level << '\n';
        cout << "durability: " << durability << "/100" << '\n';
        cout << "weight: " << weight << "lbs" << '\n';
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

    int getDurability()
    {
        return durability;
    }

    int getWeight()
    {
        return weight;
    }

~Item()
{
    delete[] item_name;
}

};

class Weapon : public Item
{
    public:
        Weapon(const char* item_name, int quantity = 0, int item_level = 0, int durability = 0, int weight = 0)
            : Item(item_name, quantity, item_level, durability, weight){}
        
        virtual void display() const override
        {
            cout << "---Weapon---\n";
            Item::display();
        }
};

class Armor : public Item
{
    public:
        Armor(const char* item_name, int quantity = 0, int item_level = 0, int durability = 0, int weight = 0)
            : Item(item_name, quantity, item_level, durability, weight){}
        
        virtual void display() const override
        {
            cout << "---Armor---\n";
            Item::display();
        }
};

class Inventory
{
    private:
        vector<Item*> items;
        int capacity;
        vector<int> itemLevels;

    public:
        Inventory(int capacity) : capacity(capacity)
        {
            items.reserve(capacity);
            itemLevels.reserve(capacity);
        }

    void addItem(Item* newItem)
    {
        if(items.size() >= capacity)
        {
            cout <<"Inventory full" << '\n';
            return;
        }
        if(newItem != nullptr)
        {
        items.push_back(newItem);
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
        cout << "Inventory capacity: " << capacity << '\n';
        cout << "Items:\n";
        for(const auto& item : items)
        {
            item->display();
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

//quicksort

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
  Inventory bags(6);
  Item* item1 = new Weapon("Frostmourne", 1, 69, 50, 30);
  bags.addItem(item1);
  Item* item2 = new Weapon("Chaotic-Axe", 1, 75, 90, 50);
  bags.addItem(item2);
  Item* item3 = new Weapon("Shattering-Katana", 1, 80, 100, 20);
  Item* item4 = new Armor("Howling Abyss", 1, 35, 65, 10);
  Item* item5 = new Armor("idontknow", 1, 98, 34, 15);
  Item* item6 = new Armor("whoknows", 1, 72, 96, 22);
  bags.addItem(item3);
  bags.addItem(item4);
  bags.addItem(item5);
  bags.addItem(item6);
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
 

 delete item1, item2, item3, item4, item5, item6;



 return 0;

}
