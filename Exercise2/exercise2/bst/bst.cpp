#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const TraversableContainer<Data> & con)
{
    con.Traverse(
        [this](const Data& dat){
            Insert(dat);
        }
    );
}

template <typename Data>
BST<Data>::BST(MappableContainer<Data> && con) noexcept
{
    con.Map(
        [this](Data& dat){
            Insert(std::move(dat));
        }
    );
}

template<typename Data>
BST<Data>& BST<Data>::operator=(const BST& bst){
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}

template<typename Data>
BST<Data>& BST<Data>::operator=(BST&& bst) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept{

    BTInOrderIterator<Data> iter1(*this);
    BTInOrderIterator<Data> iter2(bst);

    while(!iter1.Terminated() && !iter2.Terminated()) {
        if(*iter1 != *iter2) {
            return false;
        }

        ++iter1;
        ++iter2;
    }

    if(iter1.Terminated() && iter2.Terminated()) {
        return true;
    }

    return false;
}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

template <typename Data>
const Data& BST<Data>::Min() const{
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return FindPointerToMin(root)->element;
}

template <typename Data>
Data BST<Data>::MinNRemove(){
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return DataNDelete(DetachMin(root));
}

template <typename Data>
void BST<Data>::RemoveMin(){
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    delete DetachMin(root);
}

template <typename Data>
const Data& BST<Data>::Max() const{
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return FindPointerToMax(root)->element;
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return DataNDelete(DetachMax(root));
}

template <typename Data>
void BST<Data>::RemoveMax(){
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    delete DetachMax(root);
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const{
    NodeLnk* const* temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    return (*temp)->element;
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
    NodeLnk** temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    return DataNDelete(Detach(*temp));
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
    NodeLnk** temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    delete Detach(*temp);
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& dat) const{
    NodeLnk* const* temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    return (*temp)->element;
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
    NodeLnk** temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    return DataNDelete(Detach(*temp));
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){
    NodeLnk** temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    delete Detach(*temp);
}

template <typename Data>
bool BST<Data>::Insert(const Data& dat){
    NodeLnk*& temp = FindPointerTo(root, dat);
    bool result = false;

    if(temp == nullptr) {
        temp = new NodeLnk(dat);
        result = true;
        ++size;
    }

    return result;
}

template <typename Data>
bool BST<Data>::Insert(Data&& dat) noexcept{
    NodeLnk*& temp = FindPointerTo(root, dat);
    bool result = false;

    if(temp == nullptr) {
        temp = new NodeLnk(std::move(dat));
        result = true;
        ++size;
    }

    return result;
}

template <typename Data>
bool BST<Data>::Remove(const Data& dat){
    NodeLnk*& temp = FindPointerTo(root, dat);
    bool result = false;

    if(temp != nullptr) {
        delete Detach(temp);
        result = true;
    }

    return result;
}

template <typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept{
    return (FindPointerTo(root, dat) != nullptr);
}

template<typename Data>
void BST<Data>::Clear(){
    BinaryTreeLnk<Data>::Clear();
}







template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* nod) {
    Data dat{};
    std::swap(dat, nod->element);
    delete nod;

    return dat;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& nod) noexcept{
    if(nod != nullptr) {
        if(!nod->HasLeftChild()){
            return Skip2Right(nod);
        }
        else if(!nod->HasRightChild()){
            return Skip2Left(nod);
        }
        else{
            NodeLnk* temp = DetachMax(nod->leftChild);
            std::swap(nod->element, temp->element);
            return temp;
        }
    }
    return nullptr;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& nod) noexcept{
    return Skip2Right(FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& nod) noexcept{
    return Skip2Left(FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& nod) noexcept{
    NodeLnk* temp = nullptr;

    if(nod != nullptr){
        std::swap(temp, nod->leftChild);
        std::swap(temp, nod);
        --size;
    }

    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& nod) noexcept{
    NodeLnk* temp = nullptr;

    if(nod != nullptr){
        std::swap(temp, nod->rightChild);
        std::swap(temp, nod);
        --size;
    }

    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& nod) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& nod) const noexcept{
    NodeLnk* const* temp = &nod;

    if(*temp != nullptr) {
        while((*temp)->leftChild != nullptr){
            temp = &(*temp)->leftChild;
        }
    }

    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& nod) noexcept{
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& nod) const noexcept{
    NodeLnk* const* temp = &nod;

    if(*temp != nullptr){
        while((*temp)->rightChild != nullptr){
            temp = &(*temp)->rightChild;
        }
    }
    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& nod, const Data& dat) noexcept{
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & nod, const Data& dat) const noexcept{
    NodeLnk* const* temp = &nod;

    if(*temp != nullptr) {
        if(nod->element == dat){
            return *temp;
        }
        else if(nod->element < dat){
            temp = &(FindPointerTo(nod->rightChild, dat));
        }
        else{
            temp = &(FindPointerTo(nod->leftChild, dat));
        }
    }
    
    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& nod, const Data& dat) noexcept{
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*> (this)->FindPointerToPredecessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(NodeLnk* const& nod, const Data& dat) const noexcept{
    NodeLnk* const * curr = &nod;
    NodeLnk* const * temp = nullptr;

    while(*curr != nullptr && (*curr)->element != dat){
        if((*curr)->element < dat){
            temp = curr;
            curr = &((*curr)->rightChild);
        }
        else if((*curr)->element > dat){
            curr = &((*curr)->leftChild);
        }
    }
    if(*curr != nullptr && (*curr)->HasLeftChild()){
        return &FindPointerToMax((*curr)->leftChild);
    }
    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& nod, const Data& dat) noexcept{
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & nod, const Data& dat) const noexcept{
    NodeLnk* const * curr = &nod;
    NodeLnk* const * temp = nullptr;

    while(*curr != nullptr && (*curr)->element != dat){
        if((*curr)->element > dat){
            temp = curr;
            curr = &((*curr)->leftChild);
        }
        else if((*curr)->element < dat){
            curr = &((*curr)->rightChild);
        }
    }
    if(*curr != nullptr && (*curr)->HasRightChild()){
        return &FindPointerToMin((*curr)->rightChild);
    }
    return temp;
}

/* ************************************************************************** */
}
