
namespace lasd {

/* ************************************************************************** */

template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& con) : Vector<Data>(con.Size() * 2) {
    con.Traverse([this](const Data& dat){
        Push(dat);
    });
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& con) noexcept : Vector<Data>(con.Size() * 2) {
    con.Map([this](Data& dat){
        Push(std::move(dat));
    });
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& con) : Vector<Data>(con) {
    topIndex = con.topIndex;
}

template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& con) noexcept : Vector<Data>(std::move(con)){
    std::swap(topIndex, con.topIndex);
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& con) {
    Vector<Data>::operator=(con);
    topIndex = con.topIndex;
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& con) noexcept {
    Vector<Data>::operator=(std::move(con));
    std::swap(topIndex, con.topIndex);
    return *this;
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& con) const noexcept {
    if(Size() == con.Size()){
        for(unsigned long i=0; i<Size(); ++i){
            if(elements[i] != con.elements[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& con) const noexcept {
    return !operator==(con);
}

template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(topIndex==0){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[topIndex-1];
}

template <typename Data>
Data& StackVec<Data>::Top() {
    if(topIndex==0){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[topIndex-1];
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    --topIndex;
    Reduce();
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[--topIndex];
    Reduce();
}

template <typename Data>
void StackVec<Data>::Push(const Data& dat) {
    Expand();
    elements[topIndex++] = dat;
}

template <typename Data>
void StackVec<Data>::Push(Data&& dat) noexcept {
    Expand();
    elements[topIndex++] = std::move(dat);
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return (topIndex==0);
}

template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
    return topIndex;
}

template <typename Data>
void StackVec<Data>::Clear() {
    topIndex = 0;
    Vector<Data>::Resize(DEFAULT_CAPACITY);
}

template <typename Data>
void StackVec<Data>::Expand() {
    if(topIndex >= size){
        Vector<Data>::Resize(size * 2);
    }
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if(size>DEFAULT_CAPACITY && topIndex<=size/4){
        Vector<Data>::Resize(size / 2);
    }
}

template <typename Data>
void StackVec<Data>::Traverse(TraverseFun fun) const{
    this->PostOrderTraverse(fun);
}

template <typename Data>
void StackVec<Data>::Map(MapFun fun){
    this->PostOrderMap(fun);
}

/* ************************************************************************** */

}
