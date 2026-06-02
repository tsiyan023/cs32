


#include "Set.h"

Set::Set()               
{
    numOfNode = 0;
}

Set::~Set()         
{
    if (!empty())
    {
    Node *e = head->prev;
    Node *p = head;
    while (p != e)
    {
        Node *nex = p->next;
        delete p;
        p = nex;
    }
    delete p;
    }
}

Set::Set(const Set& other)


{
    numOfNode = 0;
    Node *p = other.head;
    if (other.empty())
    {
        return;
    }
    for (p; p != other.head->prev; p = p->next)
    {
        insert(p->value);
    }
    insert(p->value);
}

Set Set::operator=(const Set& rhs)


{
    if (this != &rhs)
    {
        Set temp(rhs);
        swap(temp);
    }
    return *this;
}


bool Set::empty() const  
{
    return numOfNode==0;
}


int Set::size() const    
{
    return numOfNode;
}


bool Set::insert(const ItemType& value)


{
    
    if (contains(value))
    {
        std::cerr << "the value you want to insert is already contained" << std::endl;
        return false;
    }
    
    
    if (empty())
    {
        head = new Node;
        head->value = value;
        head->prev = head;
        head->next = head;
        numOfNode++;
        return true;
    }
    
    
    if (value < head->value)
    {
        Node *add = new Node;
        
        add->value = value;
        
        add->prev = head->prev;
        add->next = head;
    
        head->prev->next = add;
        head->prev = add;

        head = add;
        numOfNode++;
        return true;
    }
    
    else if (value > head->prev->value)
    {
        Node *add = new Node;
        
        add->value = value;
        
        add->next = head;
        add->prev = head->prev;
        
        head->prev->next = add;
        head->prev = add;
        numOfNode++;
        return true;
    }
    
    else
    {
        Node *p = head;
        for (p; p != head->prev; p = p->next)
        {
            if (value > p->value && value < p->next->value)
                break;
        }
        
        Node *add = new Node;
        
        add->value = value;
        
        add->prev = p;
        add->next = p->next;
        
        p->next->prev = add;
        p->next = add;
        numOfNode++;
        return true;
    }
}


bool Set::erase(const ItemType& value)


{
    if (!contains(value))
    {
        std::cerr << "the value you want to remove is not in the list!!!" << std::endl;
        return false;
    }
    else
    {
        Node *p = head;
        for (p; p != head->prev; p = p->next)
        {
            if (value == p->value)
                break;
        }
        if (p->value == value)  
        {
            if (p == head)      
            {
                head = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            numOfNode--;
            return true;
        }
        else
            return false;

    }
}


bool Set::contains(const ItemType& value) const

{
    if (empty())
        return false;
    else
    {
        Node *p = head;
        for (p; p != head->prev; p = p->next)
        {
            if (value == p->value)
                return true;
        }
        if (value == p->value)      
            return true;
        return false;
    }
}

bool Set::get(int pos, ItemType& value) const


{
    if (empty())
        return false;
    
    if (pos >=0 && pos < numOfNode)
    {
        int countNum = 1;
        Node *p = head;
        for (p; p != head->prev  &&  countNum <= pos; p = p->next,countNum++)
            
        ;
        if (countNum == pos+1)
        {
            value = p->value;
        }
        return true;
    }
    else
    {
        std::cerr << "the number has to be with in the range"<<std::endl;
        return false;
    }
    
}

void Set::swap(Set& other)

{
    
    int tempNum = other.numOfNode;
    other.numOfNode = numOfNode;
    numOfNode = tempNum;
    
    
    Node *tempH = other.head;
    other.head = head;
    head = tempH;
    
}

void Set::dump() const
{
    if (empty())
        std::cerr << "there is no element!!!" << std::endl;
    else
    {
    Node *p = head;
    std::cerr << "the element in the list in order is:\n";
    for (p; p != head->prev; p = p->next)
    {
        std::cerr << p->value << std::endl;
    }
    std::cerr << p->value << std::endl;
    }
}


void unite(const Set& s1, const Set& s2, Set& result)
{
    ItemType temp;
    
    if (&result == &s1)
    {
        for (int i = 0; i < s2.size(); i++)
        {
            s2.get(i, temp);
            result.insert(temp);
        }

    }
    else if(&result == &s2)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            s1.get(i, temp);
            result.insert(temp);
        }
        
    }
    
    else
    {
    for (int i = 0; result.size() != 0;)
    {
        result.get(i, temp);
        result.erase(temp);
    }
    
    for (int i = 0; i < s1.size(); i++)
    {
        s1.get(i, temp);
        result.insert(temp);
    }
    
    for (int i = 0; i < s2.size(); i++)
    {
        s2.get(i, temp);
        result.insert(temp);
    }
    }
}

void subtract(const Set& s1, const Set& s2, Set& result)
{
    ItemType temp;
    
    if( &result == &s2)
    {
        Set tempS = s2;
        for (int i = 0; i < s1.size(); i++)
        {
            s1.get(i, temp);
            result.insert(temp);
        }
        
        for (int i = 0; i < tempS.size(); i++)
        {
            tempS.get(i, temp);
            result.erase(temp);
        }

    }
    else if (&result == &s1)
    {
        for (int i = 0; i < s2.size(); i++)
        {
            s2.get(i, temp);
            result.erase(temp);
        }
    }

    
    else
    {
    for (int i = 0; result.size() != 0;)
    {
        result.get(i, temp);
        result.erase(temp);
    }
    
    for (int i = 0; i < s1.size(); i++)
    {
        s1.get(i, temp);
        result.insert(temp);
    }
    
    for (int i = 0; i < s2.size(); i++)
    {
        s2.get(i, temp);
        result.erase(temp);
    }
    }
}


