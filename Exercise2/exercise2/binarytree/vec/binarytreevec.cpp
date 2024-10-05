
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& dat, unsigned long index, Vector<NodeVec*> *vec){
    element = dat;
    currIndex = index;
    treePtr = vec;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& dat, unsigned long index, Vector<NodeVec*> *vec){
    element = std::move(dat);
    currIndex = index;
    treePtr = vec;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& nod) {
    element = nod.element;
    currIndex = nod.currIndex;
    treePtr = nod.treePtr;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec&& nod) noexcept {
    std::swap(element, nod.element);
    std::swap(currIndex, nod.currIndex);
    std::swap(treePtr, nod.treePtr);
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& nod) {
    element = nod.element;
    currIndex = nod.currIndex;
    treePtr = nod.treePtr;

    return *this;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& nod) noexcept {
    std::swap(element, nod.element);
    std::swap(currIndex, nod.currIndex);
    std::swap(treePtr, nod.treePtr);

    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& nod) const noexcept {
    return BinaryTree<Data>::Node::operator==(nod);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& nod) const noexcept {
    return !(element == nod.element);
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return element;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return element;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return ((!HasLeftChild()) && (!HasRightChild()));
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return (2 * currIndex + 1 < treePtr->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return (2 * currIndex + 2 < treePtr->Size());
}

template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(!HasLeftChild())
        throw std::out_of_range(ERRMSG_LEFT_CHILD_MISSING);
    
    return *(treePtr->operator[](2*currIndex + 1));
}

template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(!HasLeftChild())
        throw std::out_of_range(ERRMSG_LEFT_CHILD_MISSING);
    
    return *(treePtr->operator[](2*currIndex + 1));
}

template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(!HasRightChild())
        throw std::out_of_range(ERRMSG_RIGHT_CHILD_MISSING);
    
    return *(treePtr->operator[](2*currIndex + 2));
}

template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(!HasRightChild())
        throw std::out_of_range(ERRMSG_RIGHT_CHILD_MISSING);
    
    return *(treePtr->operator[](2*currIndex + 2));
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& con){
    size = con.Size();
    treeVec.Resize(size);

    unsigned long index = 0;
    con.Traverse(
        [this, &index](const Data& dat){
            treeVec[index] = new NodeVec(dat, index, &treeVec);
            ++index;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& con){
    size = con.Size();
    treeVec.Resize(size);

    unsigned long int index = 0;
    con.Map(
        [this, &index](Data& dat){
            treeVec[index] = new NodeVec(std::move(dat), index, &treeVec);
            ++index;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& con){
    size = con.Size();
    treeVec.Resize(size);
    
    for(unsigned long i = 0; i < size; i++){
        treeVec[i] = new NodeVec(con.treeVec[i]->element, i, &treeVec);
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& con) noexcept {
    std::swap(size, con.size);
    std::swap(treeVec, con.treeVec);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {            
    Clear();
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& con){

    if (this->Empty()){
        if (!con.Empty()) {
            treeVec.Resize(con.Size());
            for(unsigned long i = 0; i < con.Size(); i++){
                treeVec[i] = new NodeVec(con.treeVec[i]->element, i, &treeVec);
            }
        }
    }
    else {
        if (con.Empty()){
            Clear();
        }
        else {
            treeVec.Resize(con.Size());
            for(unsigned long i = 0; i < size; i++){
                treeVec[i] = new NodeVec(con.treeVec[i]->element, i, &treeVec);
            }
        }
    }

    size = con.Size();
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& con) noexcept{
    std::swap(size, con.size);
    std::swap(treeVec, con.treeVec);

    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& con) const noexcept{
    return BinaryTree<Data>::operator==(con);
}

template <typename Data>
inline bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& con) const noexcept {
    return !(*this == con);
}

template <typename Data>
const typename BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const{
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return *(treeVec[0]);
}

template <typename Data>
typename BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(this->Empty())
        throw std::length_error(ERRMSG_EMPTY_TREE);
    
    return *(treeVec[0]);
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    for (unsigned long i = 0; i < size; ++i){
        delete treeVec[i];
    }

    treeVec.Clear();
    size = 0;
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
    for (unsigned long i = 0; i < size; ++i){
        fun(treeVec[i]->Element());
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {
    for (unsigned long i = 0; i < size; ++i){
        fun(treeVec[i]->Element());
    }
}


/* ************************************************************************** */

}
