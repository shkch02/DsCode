#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include "BagInterface.h"
#include <vector>
template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6;  
    ItemType items[DEFAULT_CAPACITY]; // bag items
    int itemCount; // count of bag items
    int maxItems; // max capacity of the bag
    int getIndexOf(const ItemType& target) const;
public:
    ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& someItem);
    bool remove(const ItemType& someItem);
    void clear();
    bool contains(const ItemType& target) const;
    int getFrequencyOf(const ItemType& target) const;
    std::vector<ItemType> toVector() const; 
};  
// end ArrayBag