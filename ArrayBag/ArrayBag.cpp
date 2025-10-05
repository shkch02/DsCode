 template<class ItemType>
 class BagInterface
 {
 public:
 virtual int getCurrentSize() const = 0;
 virtual bool isEmpty() const = 0;
 virtual bool add(const ItemType& someItem) = 0;
 virtual bool remove(const ItemType& someItem) = 0;
 virtual void clear() = 0;
 virtual int getFrequencyOf(const
 ItemType& target) const = 0;
 virtual bool contains(const
 ItemType& target) const = 0;
 virtual std::vector<ItemType> toVector() const = 0;
 virtual ~BagInterface()
 };
 
 
template<class ItemType>
ArrayBag<ItemType>::ArrayBag() 
: itemCount(0), maxItems(DEFAULT_CAPACITY)
 {
 }  
// end default constructo

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{ 
    return itemCount;
}// end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{    
    return itemCount == 0;
}// end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& someItem)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = someItem;
    itemCount++;
    }// end if
    return hasRoomToAdd;
}// end add

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
    bagContents.push_back(items[i]);
    return bagContents;
}// end toVector