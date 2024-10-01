
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> & travCon)
{
    bool success = true;

    travCon.Fold(
        [this](const Data& dat, bool successFold){
            successFold &= Insert(dat);
        },
        success
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

    travCon.Fold(
        [this](const Data& dat, bool successFold){
            successFold &= Remove(dat);
        },
        success
    );

    return success;
}

template <typename Data>
inline bool lasd::DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> & travCon)
{
    bool success = false;

    travCon.Fold(
        [this](const Data& dat, bool successFold){
            successFold |= Insert(dat);
        },
        success
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

    travCon.Fold(
        [this](const Data& dat, bool successFold){
            successFold |= Remove(dat);
        },
        success
    );

    return success;
}

/* ************************************************************************** */

}
