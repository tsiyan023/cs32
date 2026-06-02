#ifndef NEWSET_INCLUDED
#define NEWSET_INCLUDED

#include <iostream>
#include <string>

const int DEFAULT_MAX_ITEMS = 200;
typedef unsigned long ItemType;

class Set
{
public:
    Set(const int cap = DEFAULT_MAX_ITEMS);

    ~Set();

    Set(const Set& other);

    Set operator=(const Set& rhs);

    bool empty() const;

    int size() const;

    bool insert(const ItemType& value);

    bool erase(const ItemType& value);

    bool contains(const ItemType& value) const;

    bool get(int i, ItemType& value) const;

    void swap(Set& other);

    void dump() const;
private:

    ItemType *m_set;
    int m_numberOfItems;
    int newLim;

};

#endif
