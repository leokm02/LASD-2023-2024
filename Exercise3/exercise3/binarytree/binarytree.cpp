#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

//Node
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nod) const noexcept {
  bool equal = false;
  equal = (this->Element() == nod.Element());

  if (equal){
    equal = false;

    if (this->HasLeftChild() && nod.HasLeftChild()){
      equal = (this->LeftChild() == nod.LeftChild());
    }
    else if (!this->HasLeftChild() && !nod.HasLeftChild()){
      equal = true;
    }
  }

  if (equal){
    equal = false;

    if (this->HasRightChild() && nod.HasRightChild()){
      equal = (this->RightChild() == nod.RightChild());
    }
    else if (!this->HasRightChild() && !nod.HasRightChild()){
      equal = true;
    }
  }

  return equal;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}

/* ************************************************************************** */

//BinaryTree
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& bt) const noexcept {
    if(this->Size() == bt.Size() && !this->Empty()) {
        if(this->Empty()){
            return true;
        }
        return (Root() == bt.Root());
    }
    return false;
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& bt) const noexcept {
    return !(*this == bt);
}

template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
    if(!this->Empty()) {
        PreOrderTraverse(fun, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
    if(!this->Empty()) {
        PostOrderTraverse(fun, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
    if(!this->Empty()) {
        InOrderTraverse(fun, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
    if(!this->Empty()) {
        BreadthTraverse(fun, this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node& nod) const {

    fun(nod.Element());

    if(nod.HasLeftChild()) {
        PreOrderTraverse(fun, nod.LeftChild());
    }
    if(nod.HasRightChild()) {
        PreOrderTraverse(fun, nod.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node& nod) const {

    if(nod.HasLeftChild()) {
        PostOrderTraverse(fun, nod.LeftChild());
    }
    if(nod.HasRightChild()) {
        PostOrderTraverse(fun, nod.RightChild());
    }
    
    fun(nod.Element());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node& nod) const {

    if(nod.HasLeftChild()) {
        InOrderTraverse(fun, nod.LeftChild());
    }

    fun(nod.Element());

    if(nod.HasRightChild()) {
        InOrderTraverse(fun, nod.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node& nod) const {
    QueueVec<const Node*> que;

    que.Enqueue(&nod);

    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }

        que.Dequeue();
    }
}

/* ************************************************************************** */

//MutableBinaryTree
template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun) {
    PreOrderMap(fun);
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
    if(!this->Empty()){
        PreOrderMap(fun, this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
    if(!this->Empty()) {
        PostOrderMap(fun, this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
    if(!this->Empty()) {
        InOrderMap(fun, this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
    if(!this->Empty()) {
        BreadthMap(fun, this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode& nod) {

    fun(nod.Element());
    
    if(nod.HasLeftChild()) {
        PreOrderMap(fun, nod.LeftChild());
    }
    if(nod.HasRightChild()) {
        PreOrderMap(fun, nod.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode& nod) {

    if(nod.HasLeftChild()) {
        PostOrderMap(fun, nod.LeftChild());
    }
    if(nod.HasRightChild()) {
        PostOrderMap(fun, nod.RightChild());
    }

    fun(nod.Element());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode& nod) {

    if(nod.HasLeftChild()) {
        InOrderMap(fun, nod.LeftChild());
    }

    fun(nod.Element());

    if(nod.HasRightChild()) {
        InOrderMap(fun, nod.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode& nod) {
    lasd::QueueVec<MutableNode*> que;

    que.Enqueue(&nod);

    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }
        que.Dequeue();
    }
}

/* ************************************************************************** */

//BTPreOrderIterator
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& iter) {
    root = iter.root;
    curr = iter.root;
    stk = iter.stk;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);
        
    return curr->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    if(curr->HasRightChild())
        stk.Push(&(curr->RightChild()));
    if(curr->HasLeftChild())
        stk.Push(&(curr->LeftChild()));
    
    if(stk.Empty()){
        curr = nullptr;
    }
    else{
        curr = stk.TopNPop(); 
    }

    return (*this);
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();
}


//BTPreOrderMutableIterator
template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator& iter){
    return BTPreOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator&& iter) noexcept{
    return BTPreOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator& iter) const noexcept{
    return BTPreOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    return const_cast<Data&>(curr->Element());
}


/* ************************************************************************** */

//BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> & bt)
{
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;

        GetLeftmostLeaf();
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator & iter)
{
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator && iter) noexcept
{
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator & iter)
{
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(BTPostOrderIterator && iter) noexcept
{
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator & iter) const noexcept
{
    if(root!=iter.root || curr!=iter.curr || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator & iter) const noexcept
{
    return !(*this == iter);
}

template <typename Data>
const Data &BTPostOrderIterator<Data>::operator*() const
{
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);
        
    return curr->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept
{
    return (curr == nullptr);
}

template <typename Data>
BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++()
{
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);
    
    if(stk.Empty()){
        curr = nullptr;
    }
    else{
        if(stk.Top()->HasRightChild() && (&stk.Top()->RightChild() != curr)){
            curr = &stk.Top()->RightChild();
            GetLeftmostLeaf();
        }
        else{
            curr = stk.TopNPop();
        }
    }

    return (*this);
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();

    GetLeftmostLeaf();
}

template <typename Data>
void BTPostOrderIterator<Data>::GetLeftmostLeaf() {
    if(!this->Terminated()){
        while(curr->HasLeftChild()) {
            stk.Push(curr);
            curr = &curr->LeftChild();
        }
        if(curr->HasRightChild()) {
            stk.Push(curr);
            curr = &curr->RightChild();
            GetLeftmostLeaf();
        }
    }
}


// BTPostOrderMutableIterator
template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator& iter){
    BTPostOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator&& iter) noexcept{
    BTPostOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator& iter) const noexcept{
    return BTPostOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    return const_cast<Data&>(curr->Element());
}

/* ************************************************************************** */

//BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;

        GetLeftmostNode();
    }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iter) {
    root = iter.root;
    curr = iter.root;
    stk = iter.stk;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);
        
    return curr->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    if(curr->HasRightChild()){
        curr = &(curr->RightChild());
        GetLeftmostNode();
    }
    else{
        if(stk.Empty()){
            curr = nullptr;
        }
        else{
            curr = stk.TopNPop();
        }
    }

    return (*this);
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();

    GetLeftmostNode();
}

template <typename Data>
void BTInOrderIterator<Data>::GetLeftmostNode() {
    if(!this->Terminated()) {
        while(curr->HasLeftChild()) {
            stk.Push(curr);
            curr = &curr->LeftChild();
        }
    }
}


//BTInOrderMutableIterator
template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator& iter){
    BTInOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator&& iter) noexcept{
    BTInOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator& iter) const noexcept{
    return BTInOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTInOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    return const_cast<Data&>(curr->Element());
}

/* ************************************************************************** */

//BTBreadthIterator
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;
    }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& iter) {
    root = iter.root;
    curr = iter.root;
    que = iter.que;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(que, iter.que);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    que = iter.que;

    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(que, iter.que);

    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || que!=iter.que)
        return false;

    return true;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);
        
    return curr->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    if(curr->HasLeftChild()) {
        que.Enqueue(&(curr->LeftChild()));
    }
    if(curr->HasRightChild()) {
        que.Enqueue(&(curr->RightChild()));
    }
    if(que.Empty()) {
        curr = nullptr;
    } else {
        curr = que.HeadNDequeue();
    }

    return (*this);
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    curr = root;
    que.Clear();
}



//BTBreadthMutableIterator
template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator& iter){
    BTBreadthIterator<Data>::operator=(iter);
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator&& iter) noexcept{
    BTBreadthIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator& iter) const noexcept{
    return BTBreadthIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range(ERRMSG_ITERATOR_TERMINATED);

    return const_cast<Data&>(curr->Element());
}

/* ************************************************************************** */

}
