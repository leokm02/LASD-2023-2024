
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& con){
    List<Data>::operator=(con);
    return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& con) noexcept{
    List<Data>::operator=(std::move(con));
    return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& con) const noexcept{
    return List<Data>::operator==(con);
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& con) const noexcept{
    return List<Data>::operator!=(con);
}

template<typename Data>
const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template<typename Data>
Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& dat) {
    List<Data>::InsertAtBack(dat);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& dat) noexcept {
    List<Data>::InsertAtBack(dat);
}

/* ************************************************************************** */

}
