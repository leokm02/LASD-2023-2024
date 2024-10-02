#include "linear.hpp"

#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

//Linear
template <typename Data>
bool lasd::LinearContainer<Data>::operator==(const LinearContainer & con) const noexcept
{
    if(this->Size() == con.Size()){
        for(unsigned long i=0; i<this->Size(); ++i){
            if(operator[](i) != con.operator[](i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool lasd::LinearContainer<Data>::operator!=(const LinearContainer & con) const noexcept
{
    return !operator==(con);
}

template <typename Data>
const Data &lasd::LinearContainer<Data>::Front() const
{
    if(this->Empty()){
        throw std::length_error(lasd::ERRMSG_EMPTY_CONTAINER);
    }

    return operator[](0);
}

template <typename Data>
Data &lasd::LinearContainer<Data>::Front()
{
    if(this->Empty()){
        throw std::length_error(lasd::ERRMSG_EMPTY_CONTAINER);
    }

    return operator[](0);
}

template <typename Data>
const Data &lasd::LinearContainer<Data>::Back() const
{
    if(this->Empty()){
        throw std::length_error(lasd::ERRMSG_EMPTY_CONTAINER);
    }

    return operator[](this->Size() - 1);
}

template <typename Data>
Data &lasd::LinearContainer<Data>::Back()
{
    if(this->Empty()){
        throw std::length_error(lasd::ERRMSG_EMPTY_CONTAINER);
    }

    return operator[](this->Size() - 1);
}

template <typename Data>
void lasd::LinearContainer<Data>::Traverse(TraverseFun travFun) const
{
    PreOrderTraverse(travFun);
}

template <typename Data>
void lasd::LinearContainer<Data>::PreOrderTraverse(TraverseFun travFun) const
{
    for(unsigned long i=0; i < this->Size(); ++i){
        travFun(operator[](i));
    }
}

template <typename Data>
void lasd::LinearContainer<Data>::PostOrderTraverse(TraverseFun travFun) const
{
    unsigned long i = this->Size();
    while(i > 0){
        travFun(operator[](--i));
    }
}

template <typename Data>
void lasd::LinearContainer<Data>::Map(MapFun mapFun)
{
    PreOrderMap(mapFun);
}

template <typename Data>
void lasd::LinearContainer<Data>::PreOrderMap(MapFun mapFun)
{
    for(unsigned long i=0; i < this->Size(); ++i){
        mapFun(operator[](i));
    }
}

template <typename Data>
void lasd::LinearContainer<Data>::PostOrderMap(MapFun mapFun)
{
    unsigned long i = this->Size();
    while(i > 0){
        mapFun(operator[](--i));
    }
}


//SortableLinear
template <typename Data>
bool lasd::SortableLinearContainer<Data>::operator==(const SortableLinearContainer & con) const noexcept
{
    return LinearContainer<Data>::operator==(con);
}

template <typename Data>
bool lasd::SortableLinearContainer<Data>::operator!=(const SortableLinearContainer & con) const noexcept
{
    return !operator==(con);
}

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept
{
    QuickSort(0, this->Size() - 1);
}

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(const unsigned long p, const unsigned long r) noexcept
{
    if (p < r) {
        unsigned long q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q+1, r);
    }
}

template <typename Data>
unsigned long SortableLinearContainer<Data>::Partition(const unsigned long p, const unsigned long r) noexcept {
    Data x = this->operator[](p);
    unsigned long i = p-1;
    unsigned long j = r+1;

    do {
        do { j--; }
        while (x < this->operator[](j));

        do { i++; }
        while (x > this->operator[](i));

        if (i < j) {
            std::swap(this->operator[](i), this->operator[](j));
        }
    }
    while (i < j);

    return j;
}

/* ************************************************************************** */

}
