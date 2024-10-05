
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline void lasd::PreOrderMappableContainer<Data>::Map(MapFun mapFun)
{
    PreOrderMap(mapFun);
}

template <typename Data>
inline void lasd::PostOrderMappableContainer<Data>::Map(MapFun mapFun)
{
    PostOrderMap(mapFun);
}

template <typename Data>
inline void lasd::InOrderMappableContainer<Data>::Map(MapFun mapFun)
{
    InOrderMap(mapFun);
}

template <typename Data>
inline void lasd::BreadthMappableContainer<Data>::Map(MapFun mapFun)
{
    BreadthMap(mapFun);
}

/* ************************************************************************** */

}
