 #ifndef _BagInterface_h
 #define _BagInterface_h
 #include <vector>
 template<class ItemType>
 class BagInterface
 {
 public:
 /** Gets the current number of entries in this bag.
 @return the integer number of entries currently in the bag */
 virtual int getCurrentSize() const = 0;
 /** Sees whether this bag is empty.
 @return true if the bag is empty, or false if not */
 virtual bool isEmpty() const = 0;
 /** Adds a new entry to this bag
  @post if successful, someItem in stored in bag and
 count of items in the bag is increased by 1
 @param someItem the object to be added as a new entry
 @return true if addition is successful, or false if not */
 virtual bool add(const ItemType& someItem) = 0;
 /** Removes one occurrence of a given entry from this bag,
 if possible.
 @post if successful, target has been removed from the bag 
and the count of items in the bag has decreased by 1
 @param target  the entry to be removed
 @return true if removal was successful, or false if not */
 virtual bool remove(const ItemType& target) = 0;
 /** Removes all entries from this bag. 
@post bag contains no items and the count of items is 0 */
 virtual void clear() = 0;
 /** Counts the number of times a given entry appears in bag.
 @param target  the entry to be counted
 @return the number of times anEntry appears in the bag *
  virtual int getFrequencyOf(const ItemType& target) const = 0;
 /** Tests whether this bag contains a given entry.
 @param target  the entry to locate
 @return true if bag contains target, or false otherwise */
 virtual bool contains(const ItemType& target) const = 0;
 /** Returns vector with copies of all entries in the bag.
 @param bagContents a vector
 @post bagContents contains copies of all entries in the bag */
 virtual vector<ItemType> toVector() const = 0; 
};  
// end BagInterface
 #endif