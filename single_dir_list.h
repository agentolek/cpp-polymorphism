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
        SDNode *pointer;
        friend class SDList;
        iterator(SDNode *node) : pointer(node) {};
    public:
        iterator& operator++() { pointer = pointer->next; return *this;};
        iterator& operator++(int) {auto retv = *this; pointer = pointer->next; return retv;};
        T& operator*() { return pointer->value; };
        bool operator!=(const iterator& it) {return pointer != it.pointer; };
    };

    // default - force compiler to create default constructor, so no definition needed
    SDList() = default;

    // konstruktor kopiujący (?)
    SDList(const SDList& copyList)
    {
        *this = copyList;
    };

    // a co to robi? to jest taki std::move dla naszego kontenera
    // SDList(SDlist&& src)
    // {
    //     head = src.head;
    //     src.head = nullptr;
    // };

    // operator podstawienia
    SDList& operator=(const SDList* source)
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
                }
                else
                {
                    currNode->next = newNode;
                }
                currNode = currNode->next;
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

    // METODY LISTY
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

    friend std::ostream& operator<<(std::ostream& os, const SDList& lst)
    {
        os << '[';
        for (auto ptr = lst.head; ptr != nullptr; ptr = ptr->next)
            os << *ptr << " | ";
        return os << ']';
    }
};