#include "vector.hpp"

namespace lasd {

/* ************************************************************************** */

//Vector
template <typename Data>
inline lasd::Vector<Data>::Vector(const unsigned long s)
{
    size = s;
    elements = new Data[size]{};
}

template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data> & con)
{
    size = con.Size();
    elements = new Data[size]{};
    unsigned long i = 0;
    con.Traverse([this, &i](const Data& dat){
        elements[i++] = dat;
    });
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data> && con) noexcept
{
    size = con.Size();
    elements = new Data[size]{};
    unsigned long i = 0;
    con.Map([this, &i](Data& dat){
        elements[i++] = std::move(dat);
    });
}

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& con)
{
    size = con.size;
    elements = new Data[size]{};
    std::copy(con.elements, con.elements + con.size, elements);
}

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& con) noexcept
{
    std::swap(con.size, size);
    std::swap(con.elements, elements);
}

template <typename Data>
Vector<Data>::~Vector()
{
    Clear();
}

template <typename Data>
Vector<Data> &Vector<Data>::operator=(const Vector & con)
{
    Vector * newcon = new Vector(con);
    std::swap(*newcon, *this);
    delete newcon;
    return *this;
}

template <typename Data>
Vector<Data> &Vector<Data>::operator=(Vector && con) noexcept
{
    std::swap(con.size, size);
    std::swap(con.elements, elements);
    return *this;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector & con) const noexcept
{
    if(size == con.Size()){
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
bool Vector<Data>::operator!=(const Vector & con) const noexcept
{
    return !operator==(con);
}

template <typename Data>
void Vector<Data>::Clear()
{
    size = 0;
    delete[] elements;
    elements = nullptr;
}

template <typename Data>
void Vector<Data>::Resize(const unsigned long newsize)
{
    if(newsize>0){
        Data * temp = new Data[newsize]{};
        unsigned long lim = (size < newsize)? size : newsize;
        unsigned long i = 0;
        while(i<lim){
            std::swap(temp[i], elements[i]);
            ++i;
        }
        std::swap(elements, temp);
        delete[] temp;
        size = newsize;
    }
    else{
        Clear();
    }
}

template <typename Data>
const Data &Vector<Data>::operator[](const unsigned long index) const
{
    if(index>=Size()){
        throw std::out_of_range(ERRMSG_OUT_OF_BOUNDS);
    }
    return elements[index];
}

template <typename Data>
Data &Vector<Data>::operator[](const unsigned long index)
{
    if(index>=Size()){
        throw std::out_of_range(ERRMSG_OUT_OF_BOUNDS);
    }
    return elements[index];
}

template <typename Data>
const Data &Vector<Data>::Front() const
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[0];
}

template <typename Data>
Data &Vector<Data>::Front()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[0];
}

template <typename Data>
const Data &Vector<Data>::Back() const
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[Size() - 1];
}

template <typename Data>
Data &Vector<Data>::Back()
{
    if(Empty()){
        throw std::length_error(ERRMSG_EMPTY_CONTAINER);
    }
    return elements[Size() - 1];
}

/* ************************************************************************** */

//SortableVector
template <typename Data>
SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector & con)
{
    Vector<Data>::operator=(con);
    return *this;
}

template <typename Data>
SortableVector<Data> &SortableVector<Data>::operator=(SortableVector && con) noexcept
{
    Vector<Data>::operator=(std::move(con));
    return *this;
}

/* ************************************************************************** */

}
