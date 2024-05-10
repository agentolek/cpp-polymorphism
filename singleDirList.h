#pragma once
#include <iostream>

template <typename T>
class SDList
{
    struct SDNode
    {
        T value;
        SDNode *next = nullptr;

        SDNode(const T& val, SDNode* nxt = nullptr)
            : value(val), next(nxt)
        {};

        friend std::ostream& operator<<(std::ostream& os, const SDNode& node)
        {
            return os << node.value << ' ';
        }
    };

    // the first node of list, if list is empty then is nullptr
    SDNode *head = nullptr;

public:
    class iterator
    {
        friend class SDList;
        iterator(SDNode *node) : pointer(node) {};
        SDNode *pointer;
    public:
        iterator& operator++() { pointer = pointer->next; return *this;};
        iterator& operator++(int) {auto retv = *this; pointer = pointer->next; return retv;};
        T& operator*() { return pointer->value; };
        bool operator!=(const iterator& it) {return pointer != it.pointer; };
        bool operator==(const iterator& it) {return pointer == it.pointer; };
    };

    // default - force compiler to create default constructor, so no definition needed
    SDList() = default;

    // copy constructor - only takes LValues, allocates twice the memory
    SDList(SDList& copyList)
    {
        *this = copyList;
    };

    // RValues are temporary, LValues are eternal
    // only takes RValues, the double ampersand signifies an RValue reference
    SDList(SDList&& src)
    {
        head = src.head;
        // src will now be converted to a hollow object
        src.head = nullptr;
    };

    // operator podstawienia
    SDList& operator=(const SDList& source)
    {
        // this condition protects us against a = a causing undefined behavior
        if (this != &source)
        {
            clear();
            SDNode* srcNode = source.head;
            SDNode* currNode = head;
            while (srcNode != nullptr)
            {
                SDNode* newNode = new SDNode(srcNode->value);
                if (currNode == nullptr)
                {
                    currNode = newNode;
                    head = currNode;
                }
                else
                {
                    currNode->next = newNode;
                    currNode = currNode->next;
                }
                srcNode = srcNode->next;
            }
        }
        return *this;
    };

    //destruktor
    ~SDList()
    {
        clear();
    };

    iterator begin() const
    {
        return iterator(head);
    };

    iterator end() const
    {
        return iterator(nullptr);
    };

    // METODY LISTY -----------------------------------------
    void clear()
    {
        while(!empty())
        {
            popFront();
        }  
    };

    size_t size() const
    {
        size_t retv = 0;
        for (auto ptr = head; ptr != nullptr; ptr = ptr->next){
            ++retv;
        }
        return retv;
    };

    bool empty() const
    {
        return head == nullptr;
    };

    void pushFront(const T& val)
    {
        head = new SDNode(val, head);
    };

    void popFront()
    {
        if (!empty())
        {
            auto toRemove = head;
            head = head->next;
            delete toRemove;
        }
    };

    void insert(iterator it, T val)
    {   
        SDNode* newNode = new SDNode(val, it.pointer->next);
        it.pointer->next = newNode;
    }

    // warning: after removal, iterator will point to nonexistent node, but I don't think there is a good fix
    void remove(iterator removeIt)
    {
        if(removeIt != nullptr){
            
            // case if this is the first node
            if (removeIt == begin())
            {
                head = removeIt.pointer->next;
            }
            // if any other node, previous node must now point to one after
            for (auto it = begin(); it != end(); ++it)
            {
                if (it.pointer->next == removeIt.pointer)
                {
                    it.pointer->next = removeIt.pointer->next;
                    break;
                }
            }    
        }
        return;
    }

    friend std::ostream& operator<<(std::ostream& os, const SDList& lst)
    {
        for (const auto& member : lst)
        {
            os << "| " << member << " |\n";
        }
        return os;
    }
};