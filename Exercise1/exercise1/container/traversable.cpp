
namespace lasd {

/* ************************************************************************** */

//Traversable
template <typename Data>
template <typename Accumulator>
Accumulator lasd::TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator acc) const
{
    Traverse(
        [foldFun, &acc](const Data& dat){
            acc = foldFun(dat, acc);
        }
    );
    
    return acc;
}

template <typename Data>
bool lasd::TraversableContainer<Data>::Exists(const Data & dat) const noexcept
{
    Data target = dat;
    bool exists = false;

    Traverse(
        [&target, &exists](const Data& dat) {                                                 //Funzione lambda: parentesi quadre = contesto
            exists |= (dat==target);                                                         //uso il riferimento se voglio modificarlo
        }                                                                                // |= perchè basta che è true una volta
    );

    return exists;
}


//PreOrderTraversable
template <typename Data>
template <typename Accumulator>
Accumulator lasd::PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
{
    PreOrderTraverse(
        [foldFun, &acc](const Data& dat){
            acc = foldFun(dat, acc);
        }
    );
    
    return acc;
}

template <typename Data>
void lasd::PreOrderTraversableContainer<Data>::Traverse(TraverseFun travFun) const
{
    PreOrderTraverse(travFun);
}


//PostOrderTraversable
template <typename Data>
template <typename Accumulator>
Accumulator lasd::PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
{
    PostOrderTraverse(
        [foldFun, &acc](const Data& dat){
            acc = foldFun(dat, acc);
        }
    );
    
    return acc;
}

template <typename Data>
void lasd::PostOrderTraversableContainer<Data>::Traverse(TraverseFun travFun) const
{
    PostOrderTraverse(travFun);
}


//InOrderTraversable
template <typename Data>
template <typename Accumulator>
Accumulator lasd::InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
{
    InOrderTraverse(
        [foldFun, &acc](const Data& dat){
            acc = foldFun(dat, acc);
        }
    );
    
    return acc;
}

template <typename Data>
void lasd::InOrderTraversableContainer<Data>::Traverse(TraverseFun travFun) const
{
    InOrderTraverse(travFun);
}


//BreadthTraversable
template <typename Data>
template <typename Accumulator>
Accumulator lasd::BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldFun, Accumulator acc) const
{
    BreadthTraverse(
        [foldFun, &acc](const Data& dat){
            acc = foldFun(dat, acc);
        }
    );
    
    return acc;
}

template <typename Data>
void lasd::BreadthTraversableContainer<Data>::Traverse(TraverseFun travFun) const
{
    BreadthTraverse(travFun);
}

/* ************************************************************************** */

}
