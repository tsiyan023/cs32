#include "newSet.h"

#include <iostream>

Set::Set(const int cap)
{
    if (cap >= 0)
    {
        m_set = new ItemType[cap];
        newLim = cap;
        m_numberOfItems = 0;
    }
    else
        exit(1);
}

Set::~Set()
{
    delete [] m_set;
}

Set::Set(const Set& other)
{
    newLim = other.newLim;
    m_numberOfItems = other.m_numberOfItems;
    m_set = new ItemType[newLim];
    for (int k = 0; k < m_numberOfItems; k++)
    {
        m_set[k] = other.m_set[k];
    }
}

Set Set::operator=(const Set& rhs)
{
    if (this != &rhs)
    {
        Set temp = rhs;
        swap(temp);
    }
    return *this;
}

bool Set::empty() const
{
    return (m_numberOfItems == 0);
}

int Set::size() const
{
    std::cerr << "the size is " << m_numberOfItems << std::endl;
    return m_numberOfItems;
}

bool Set::insert(const ItemType& value)
{

    if (m_numberOfItems == newLim)
    {
        std::cerr << "the insert function return false!!! because the set is full!\n";
        return false;
    }

    for (int j = 0; j < m_numberOfItems; j++)
    {
        if (m_set[j] == value)
        {
            std::cerr << "the insert function return false!!! because there already is such value!\n";
            return false;
        }
    }

    for (int j = 0; j < m_numberOfItems; j++)
    {
        if (value > m_set[j])
            continue;
        else
        {
            for (int k = m_numberOfItems; k > j; k--)
            {
                m_set[k] = m_set[k-1];
            }
            m_set[j] = value;
            m_numberOfItems++;
            std::cerr << "the insert function return true!!! and the item is assigned at position" << j <<std::endl;
            return true;
        }
    }
    m_set[m_numberOfItems] = value;
    m_numberOfItems++;
    std::cerr << "the insert function return true!!! and the item is assigned at the end\n";
    return true;
}

bool Set::erase(const ItemType& value)
{

    for (int j = 0; j < m_numberOfItems; j++)
    {
        if (m_set[j] == value)
        {
            for (int k = j; k < m_numberOfItems-1; k++)
            {
                m_set[k] = m_set[k+1];
            }

            m_numberOfItems--;
            std::cerr << "the "<< j <<"th itme is successfully erased!!! the number of items is " << m_numberOfItems << std::endl;
            return true;
        }
    }
    std::cerr << "erase fail!!!\n";
    return false;

}

bool Set::contains(const ItemType& value) const
{
    for (int k = 0; k < m_numberOfItems; k++)
    {
        if (m_set[k] == value)
        {
            std::cerr << "the item " << value << "is contained in this set!!!\n";
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const
{

    if (0 <= i && i < m_numberOfItems)
    {
        value = m_set[i];
        return true;
    }
    else
        return false;
}

void Set::swap(Set& other)
{
    ItemType *temptr = m_set;
    m_set = other.m_set;
    other.m_set = temptr;

    int temp = other.newLim;
    other.newLim = newLim;
    newLim = temp;

    temp = other.m_numberOfItems;
    other.m_numberOfItems = m_numberOfItems;
    m_numberOfItems = temp;
}

void Set::dump() const
{
    for(int k = 0; k < newLim; k++)
    {
        std::cerr << m_set[k] << std::endl;
    }
}
