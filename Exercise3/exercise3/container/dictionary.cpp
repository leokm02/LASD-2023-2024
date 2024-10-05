
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> & travCon)
{
    bool success = true;

    travCon.Traverse(
        [this, &success](const Data& dat){
            success &= Insert(dat);                    //&= operazione AND bit a bit
        }
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertAll(MappableContainer<Data> && mapCon)
{
    bool success = true;

    mapCon.Map(
        [this, &success](Data& dat){
            success &= Insert(std::move(dat));
        }
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> & travCon)
{
    bool success = true;

    travCon.Traverse(
        [this, &success](const Data& dat){
            success &= Remove(dat);
        }
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> & travCon)
{
    bool success = false;

    travCon.Traverse(
        [this, &success](const Data& dat){
            success |= Insert(dat);
        }
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertSome(MappableContainer<Data> && mapCon)
{
    bool success = false;

    mapCon.Map(
        [this, &success](Data& dat){
            success |= Insert(std::move(dat));
        }
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> & travCon)
{
    bool success = false;

    travCon.Traverse(
        [this, &success](const Data& dat){
            success |= Remove(dat);
        }
    );

    return success;
}

/* ************************************************************************** */

}
