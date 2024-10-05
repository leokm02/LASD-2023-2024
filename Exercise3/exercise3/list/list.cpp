#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

//Node
template <typename Data>
inline lasd::List<Data>::Node::Node(const Data & dat)
{
    elem = dat;
}

template <typename Data>
inline lasd::List<Data>::Node::Node(Data && dat)
{
    std::swap(elem, dat);
}

template <typename Data>
lasd::List<Data>::Node::Node(const Node & nod)
{
    elem = nod.elem;
}

template <typename Data>
lasd::List<Data>::Node::Node(Node && nod) noexcept
{
    std::swap(elem, nod.elem);
    std::swap(next, nod.next);
}

template <typename Data>
bool lasd::List<Data>::Node::operator==(const Node & nod) const noexcept
{
    if(elem==nod.elem && next==nod.next) return true;
    return false;
}

template <typename Data>
bool lasd::List<Data>::Node::operator!=(const Node & nod) const noexcept
{
    return !operator==(nod);
}


//List
template <typename Data>
inline lasd::List<Data>::List(const TraversableContainer<Data> & con)
{
    con.Traverse([this](const Data& dat){
        InsertAtBack(dat);
    });
}

template <typename Data>
lasd::List<Data>::List(MappableContainer<Data> && con) noexcept
{
    con.Map([this](Data& dat){
        InsertAtBack(std::move(dat));
    });
}

template <typename Data>
lasd::List<Data>::List(const List & lst)
{
    Node * temp = lst.head;
    while(temp != nullptr){
        InsertAtBack(temp->elem);
        temp = temp->next;
    }
}

template <typename Data>
lasd::List<Data>::List(List && lst) noexcept
{
    std::swap(head, lst.head);
    std::swap(tail, lst.tail);
    std::swap(size, lst.size);
}

template <typename Data>
lasd::List<Data>::~List()
{
    Clear();
}

template <typename Data>
List<Data> & lasd::List<Data>::operator=(const List & lst)
{
    List* temp = new List<Data>(lst);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

template <typename Data>
List<Data> & lasd::List<Data>::operator=(List && lst) noexcept
{
    std::swap(head, lst.head);
    std::swap(tail, lst.tail);
    std::swap(size, lst.size);
    return *this;
}

template <typename Data>
bool lasd::List<Data>::operator==(const List & lst) const noexcept
{
    if(Size() == lst.Size()){
        Node* temp = head;
        Node* tempcmp = lst.head;
        while(temp != nullptr){
            if(temp->elem != tempcmp->elem){
                return false;
            }
            temp = temp->next;
            tempcmp = tempcmp->next;
        }
        return true;
    }
    return false;
}

template <typename Data>
bool lasd::List<Data>::operator!=(const List & lst) const noexcept
{
    return !operator==(lst);
}

template <typename Data>
void lasd::List<Data>::InsertAtFront(const Data & dat)
{
    Node* temp = new Node(dat);
    temp->next = head;
    head = temp;

    if(tail == nullptr){
        tail = head;
    }

    ++size;
}

template <typename Data>
void lasd::List<Data>::InsertAtFront(Data && dat)
{
    Node* temp = new Node(std::move(dat));
    temp->next = head;
    head = temp;

    if(tail == nullptr){
        tail = head;
    }

    ++size;
}

template <typename Data>
void lasd::List<Data>::RemoveFromFront()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if(head == nullptr){
        tail = nullptr;
    }

    --size;
}

template <typename Data>
Data lasd::List<Data>::FrontNRemove()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }

    Data ret = Front();
    RemoveFromFront();

    return ret;
}

template <typename Data>
void lasd::List<Data>::InsertAtBack(const Data & dat)
{
    Node* temp = new Node(dat);

    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;

    ++size;
}

template <typename Data>
void lasd::List<Data>::InsertAtBack(Data && dat)
{
    Node* temp = new Node(std::move(dat));

    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    
    ++size;
}

template <typename Data>
void lasd::List<Data>::Clear()
{
    while(head != nullptr){
        RemoveFromFront();
    }
}

template <typename Data>
bool List<Data>::Exists(const Data & dat) const noexcept
{
    Node * temp = head;
    while(temp != nullptr){
        if(temp->elem == dat){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename Data>
bool lasd::List<Data>::Insert(const Data & dat)
{
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(dat);
        return true;
    }
    
}

template <typename Data>
bool List<Data>::Insert(Data && dat)
{
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(std::move(dat));
        return true;
    }
}

template <typename Data>
bool List<Data>::Remove(const Data & dat)
{
    bool res = false;
    
    while(head!=nullptr && head->elem==dat){
        RemoveFromFront();
        res = true;
    }

    if(head != nullptr){
        Node* curr = head->next;
        Node* prev = head;
        Node* temp = nullptr;

        while(curr != nullptr){
            if(curr->elem == dat){
                temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                res = true;
                if(temp == tail){
                    tail = prev;
                }
                delete temp;
                --size;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
        }
    }

    return res;
}

template <typename Data>
const Data &List<Data>::operator[](const unsigned long index) const
{
    if(index >= Size()){
        throw std::out_of_range(ERRMSG_OUT_OF_BOUNDS);
    }

    if(index == Size() - 1){
        return tail->elem;
    }

    Node* temp = head;
    unsigned long i = 0;
    while(i < index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template <typename Data>
Data &List<Data>::operator[](const unsigned long index)
{
    if(index >= Size()){
        throw std::out_of_range(ERRMSG_OUT_OF_BOUNDS);
    }

    if(index == Size() - 1){
        return tail->elem;
    }

    Node* temp = head;
    unsigned long i = 0;
    while(i < index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template <typename Data>
const Data &List<Data>::Front() const
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return head->elem;
}

template <typename Data>
Data &List<Data>::Front()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return head->elem;
}

template <typename Data>
const Data &List<Data>::Back() const
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return tail->elem;
}

template <typename Data>
Data &List<Data>::Back()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return tail->elem;
}

template <typename Data>
void List<Data>::Traverse(TraverseFun travFun) const
{
    PreOrderTraverse(travFun);
}

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun travFun) const
{
    PreOrderTraverse(travFun, head);
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun travFun) const
{
    PostOrderTraverse(travFun, head);
}

template <typename Data>
void List<Data>::Map(MapFun mapFun)
{
    PreOrderMap(mapFun);
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun mapFun)
{
    PreOrderMap(mapFun, head);
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun mapFun)
{
    PostOrderMap(mapFun, head);
}

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun travFun, Node * currNod) const
{
    if(currNod != nullptr){
        travFun(currNod->elem);
        PreOrderTraverse(travFun, currNod->next);
    }
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun travFun, Node * currNod) const
{
    if(currNod != nullptr){
        PostOrderTraverse(travFun, currNod->next);
        travFun(currNod->elem);
    }
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun mapFun, Node * currNod)
{
    if(currNod != nullptr){
        mapFun(currNod->elem);
        PreOrderMap(mapFun, currNod->next);
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun mapFun, Node * currNod)
{
    if(currNod != nullptr){
        PostOrderMap(mapFun, currNod->next);
        mapFun(currNod->elem);
    }
}

/* ************************************************************************** */

}
