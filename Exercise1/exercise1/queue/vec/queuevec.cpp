#include "queuevec.hpp"

namespace lasd {

/* ************************************************************************** */


template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(DEFAULT_CAPACITY) {
    sentinel = DEFAULT_CAPACITY-1;
}

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& con) : Vector<Data>(con.Size() * 2) {
    sentinel = size-1;

    con.Traverse([this](const Data& dat) {
        Enqueue(dat);
    });
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& con) noexcept : Vector<Data>(con.Size() * 2){
    sentinel = size-1;

    con.Map([this](Data& dat) {
        Enqueue(std::move(dat));
    });
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& con) : Vector<Data>::Vector(con) {
    head = con.head;
    tail = con.tail;
    sentinel = con.sentinel;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& con) noexcept : Vector<Data>::Vector(con) {
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(sentinel, con.sentinel);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& con) {
    Vector<Data>::operator=(con);
    head = con.head;
    tail = con.tail;
    sentinel = con.sentinel;

    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& con) noexcept {
    Vector<Data>::operator=(con);
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(sentinel, con.sentinel);

    return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& con) const noexcept {
    bool ret;
    
    if(Size() == con.Size()){
        ret = true;
        if(!Empty()){
            QueueVec* temp1 = new QueueVec(*this);
            QueueVec* temp2 = new QueueVec(con);
            unsigned long s = Size();
            for(unsigned long i=0; i<s; ++i){
                if(temp1->HeadNDequeue() != temp2->HeadNDequeue()){
                    ret = false;
                    break;
                }
            }
            delete temp1;
            delete temp2;
        }
    }
    else{
        ret = false;
    }

    return ret;
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& con) const noexcept {
    return !operator==(con);
}

template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[head];
}

template <typename Data>
Data& QueueVec<Data>::Head() {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[head];
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }

    Reduce();
    sentinel = head;
    head = (head+1)%size;
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }

    Data temp = Head();
    Dequeue();
    return temp;
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& dat) {
    Expand();
    elements[tail] = dat;
    tail = (tail+1)%size;

}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& dat) noexcept {
    Expand();
    elements[tail]= std::move(dat);
    tail = (tail+1)%size;

}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return (head == tail);
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    if(head <= tail){
        return (tail-head); 
    }
    else{
        return (size-head)+tail;
    }
}

template <typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();

    size = DEFAULT_CAPACITY;
    elements = new Data[size]{};
    head = tail = 0;
    sentinel = size - 1;
}

template <typename Data>
void QueueVec<Data>::PreOrderTraverse(TraverseFun travFun) const
{
    for(unsigned long i=this->head; i!=this->tail; i=(i+1)%this->size){
        travFun(this->elements[i]);
    }
}

template <typename Data>
void QueueVec<Data>::PostOrderTraverse(TraverseFun travFun) const
{
    unsigned long i;
    if(this->tail == 0){
        i = this->size-1;
    }
    else{
        i = this->tail-1;
    }

    while(i != this->head){
        travFun(this->elements[i]);
        if(i == 0){
            i = this->size-1;
        }
        else{
            --i;
        }
    }
}

template <typename Data>
void QueueVec<Data>::PreOrderMap(MapFun mapFun)
{
    for(unsigned long i=this->head; i!=this->tail; i=(i+1)%this->size){
        mapFun(this->elements[i]);
    }
}

template <typename Data>
void QueueVec<Data>::PostOrderMap(MapFun mapFun)
{
    unsigned long i;
    if(this->tail == 0){
        i = this->size-1;
    }
    else{
        i = this->tail-1;
    }

    while(i != this->head){
        mapFun(this->elements[i]);
        if(i == 0){
            i = this->size-1;
        }
        else{
            --i;
        }
    }
}

template <typename Data>
void QueueVec<Data>::Expand()
{
    if(sentinel == tail){
        if(head <= tail){
            Vector<Data>::Resize(size*2);
            sentinel = (head-1)%size;
        }
        else{
            unsigned long newsize = size*2;

            Data* temp = new Data[newsize] {};
            unsigned long i, j;
            for(i=head, j=0; i!=tail; i=(i+1)%size, ++j){
                std::swap(elements[i], temp[j]);
            }
            std::swap(elements, temp);
            delete[] temp;

            size = newsize;
            head = 0;
            tail = j;
            sentinel = size-1;
            
        }
    }
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    if(size>DEFAULT_CAPACITY && Size()<=size/4){
        unsigned long newsize = size/2;

        Data* temp = new Data[newsize] {};
        unsigned long i, j;
        for(i=head, j=0; i!=tail; i=(i+1)%size, ++j){
            std::swap(elements[i], temp[j]);
        }
        std::swap(elements, temp);
        delete[] temp;

        size = newsize;
        head = 0;
        tail = j;
        sentinel = size-1;
    }
}


/* ************************************************************************** */

}
