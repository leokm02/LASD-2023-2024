
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nod){
    element = nod.element;

    if (nod.leftChild != nullptr) {
        leftChild = new NodeLnk(*nod.leftChild);
    }
    if (nod.rightChild != nullptr){
        rightChild = new NodeLnk(*nod.rightChild);
    }
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nod) noexcept{
    std::swap(leftChild, nod.leftChild);
    std::swap(rightChild, nod.rightChild);
    std::swap(element, nod.element);
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    delete leftChild;
    delete rightChild;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nod){
    element = nod.element;

    if (this->HasLeftChild()){
        if (nod.leftChild != nullptr){
            *leftChild = *nod.leftChild;
        }
        else {
            delete leftChild;
            leftChild = nullptr;
        }
    }
    else {
        
        if (nod.leftChild != nullptr){
            leftChild = new NodeLnk(*nod.leftChild);
        }
    }

    if (this->HasRightChild()){
        if (nod.rightChild != nullptr){
            *rightChild = *nod.rightChild;
        }
        else {
            delete rightChild;
            rightChild = nullptr;
        }
    }
    else {
        
        if (nod.rightChild != nullptr){
            rightChild = new NodeLnk(*nod.rightChild);
        }
    }

    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nod) noexcept {
    std::swap(leftChild, nod.leftChild);
    std::swap(rightChild, nod.rightChild);
    std::swap(element, nod.element);

    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& nod) const noexcept{
    return BinaryTree<Data>::Node::operator==(nod);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& nod) const noexcept {
    return !(*this == nod);
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return element;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
    return element;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
    return !(this->HasLeftChild() || this->HasRightChild());
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return (leftChild != nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    return (rightChild != nullptr);
}

template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {      //devo usare typename per far capire al compilatore che è un tipo poichè è un template
    if(!this->HasLeftChild()){
        throw std::out_of_range(ERRMSG_LEFT_CHILD_MISSING);    
    }
    else{
        return *leftChild;
    }
}

template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(!this->HasRightChild()){
        throw std::out_of_range(ERRMSG_RIGHT_CHILD_MISSING);
    }
    else{
        return *rightChild;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {      //devo usare typename per far capire al compilatore che è un tipo poichè è un template
    if(!this->HasLeftChild()){
        throw std::out_of_range(ERRMSG_LEFT_CHILD_MISSING);    
    }
    else{
        return *leftChild;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild(){
    if(!this->HasRightChild()){
        throw std::out_of_range(ERRMSG_RIGHT_CHILD_MISSING);
    }
    else{
        return *rightChild;
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;                            
    que.Enqueue(&root);

    con.Traverse(
        [&que](const Data& dat){
            NodeLnk *& temp = *que.HeadNDequeue();        
            temp = new NodeLnk(dat);
            que.Enqueue(&temp->leftChild);
            que.Enqueue(&temp->rightChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;                          
    que.Enqueue(&root);

    con.Map(
        [&que](Data & dat){
            NodeLnk *& temp = *que.HeadNDequeue();    
            temp = new NodeLnk(std::move(dat));
            que.Enqueue(&temp->leftChild);
            que.Enqueue(&temp->rightChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& con){
    if (con.root != nullptr) {
        root = new NodeLnk(*con.root);
        size = con.size;
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& con) noexcept{
    std::swap(root, con.root);
    std::swap(size, con.size);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    Clear();
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& con) {
    if (root == nullptr){
        if (con.root != nullptr){
            root = new NodeLnk(*con.root);
        }
    }
    else {
        if (con.root == nullptr) {
            delete root;
            root = nullptr;
        }
        else {
            *root = *(con.root);
        }
    }

    size = con.size;
    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& con) noexcept {
    std::swap(root, con.root);
    std::swap(size, con.size);

    return *this;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& con) const noexcept{
    return BinaryTree<Data>::operator==(con);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& con) const noexcept {
    return !(*this == con);
}

template <typename Data>
const typename BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::Root() const {      
    if(this->Empty()) {
        throw std::length_error(ERRMSG_EMPTY_TREE);
    }
    return *root;
}

template <typename Data>
typename BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {       
    if(this->Empty()) {
        throw std::length_error(ERRMSG_EMPTY_TREE);
    }
    return *root;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    root = nullptr;
    size = 0;
}

/* ************************************************************************** */

}
