#ifndef ANATOOL_CORE_OBJECT_GETTER_H
#define ANATOOL_CORE_OBJECT_GETTER_H

#include "anatool/Core/Types.h"

#include "cetlib_except/exception.h"
#include "art/Framework/Principal/Event.h"
#include "canvas/Persistency/Common/FindManyP.h"

namespace ant
{

/**
 *  @brief  A class to help with the legwork of getting objects and thier associations in LArSoft
 */
class ObjectGetter
{
public:
    /**
     *  @brief  Default constructor
     *
     *  @param  event the event
     *  @param  defaultLabel the default producer label
     */
    ObjectGetter(const art::Event *pEvent, const std::string &defaultLabel);

    /**
     *  @brief  Get the PFParticles with the given label
     *
     *  @param  label the label of the PFParticle producer
     */
    PFParticleVector GetPFParticles(const std::string &label = "");

    /**
     *  @brief  Get the clusters associated with the input PFParticle
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated clusters
     */
    ClusterVector GetAssociatedClusters(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the space points associated with the input PFParticle
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated space points
     */
    SpacePointVector GetAssociatedSpacePoints(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the vertex associated with the input PFParticle
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated vertex
     */
    Vertex_p GetAssociatedVertex(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Check if the input PFParticle has an associated track
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  if there is an associated track
     */
    bool HasAssociatedTrack(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Check if the input PFParticle has an associated shower
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  if there is an associated shower
     */
    bool HasAssociatedShower(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the track associated with the input PFParticle
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated track
     */
    Track_p GetAssociatedTrack(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the shower associated with the input PFParticle
     *
     *  @param  particle the PFParticle
     *  @param  pfParticleLabel the label of the PFParticle producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated shower
     */
    Shower_p GetAssociatedShower(const PFParticle_p &particle, const std::string &pfParticleLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the hits associated with the input Cluster
     *
     *  @param  cluster the Cluster
     *  @param  clusterLabel the label of the Cluster producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated hits
     */
    HitVector GetAssociatedHits(const Cluster_p &cluster, const std::string &clusterLabel = "", const std::string &associationLabel = "");
    
    /**
     *  @brief  Get the hit associated with the input SpacePoint
     *
     *  @param  spacePoint the SpacePoint
     *  @param  spacePointLabel the label of the SpacePoint producer
     *  @param  associationLabel the label of the association producer
     *
     *  @param  the associated hits
     */
    Hit_p GetAssociatedHit(const SpacePoint_p &spacePoint, const std::string &spacePointLabel = "", const std::string &associationLabel = "");

private:
    template <class T>
    using PtrVector = std::vector< art::Ptr<T> >;

    template <class T>
    using CollectionHandle = art::Handle<std::vector<T> >;

    template <class T>
    using CollectionNameMap = std::unordered_map<std::string, CollectionHandle<T> >;

    /**
     *  @breif  Check if the input label is empty, and if so return the default label
     *
     *  @param  label the input label
     *
     *  @return a valid label
     */
    std::string GetValidLabel(const std::string &label) const;

    /**
     *  @brief  Get a collection of an arbitrary type from the event
     *
     *  @param  collectionNameMap the mapping from collection name to handle
     *  @param  label the label of the producer of the collection
     *
     *  @return a vector of art::Ptr to the objects in the collection requested
     */
    template<class T>
    PtrVector<T> GetCollection(CollectionNameMap<T> &collectionNameMap, const std::string &label);

    /**
     *  @brief  Get the collection handle for the objects of type T with the given label
     *
     *          If the given collectionNameMap doesn't contain the objects with that label, they will be read from the event
     *
     *  @param  collectionNameMap the mapping from collection name to handle
     *  @param  label the label of the producer of the collection
     *
     *  @return the handle to the requested collection
     */
    template<class T>
    CollectionHandle<T> GetHandle(CollectionNameMap<T> &collectionNameMap, const std::string &label);

    /**
     *  @brief  Get the objects of type A associated to the input object of type B
     *
     *  @param  object the input object
     *  @param  handle the handle to the collection of objects of type B
     *  @param  label the label of the producer of the association
     *
     *  @return the associated objects
     */
    template<class A, class B>
    PtrVector<A> GetManyAssociated(const art::Ptr<B> &object, const CollectionHandle<B> &handle, const std::string &label) const;
    
    /**
     *  @brief  Get the object of type A associated to the input object of type B
     *
     *  @param  object the input object
     *  @param  handle the handle to the collection of objects of type B
     *  @param  label the label of the producer of the association
     *
     *  @return the associated object
     */
    template<class A, class B>
    art::Ptr<A> GetSingleAssociated(const art::Ptr<B> &object, const CollectionHandle<B> &handle, const std::string &label) const;

    const art::Event                     *m_pEvent;                ///< The Event
    std::string                           m_defaultLabel;          ///< The default producer label to use when getting collections
    CollectionNameMap<recob::Hit>         m_hitCollections;        ///< The Hit collections
    CollectionNameMap<recob::PFParticle>  m_pfParticleCollections; ///< The PFParticle collections
    CollectionNameMap<recob::Cluster>     m_clusterCollections;    ///< The Cluster collections
    CollectionNameMap<recob::SpacePoint>  m_spacePointCollections; ///< The SpacePoint collections
    CollectionNameMap<recob::Vertex>      m_vertexCollections;     ///< The Vertex collections
    CollectionNameMap<recob::Track>       m_trackCollections;      ///< The Track collections
    CollectionNameMap<recob::Shower>      m_showerCollections;     ///< The Shower collections
};

// -----------------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------------
    
template<class T>
inline ObjectGetter::PtrVector<T> ObjectGetter::GetCollection(CollectionNameMap<T> &collectionNameMap, const std::string &label)
{
    const auto handle = this->GetHandle(collectionNameMap, label);

    PtrVector<T> collection;
    for (unsigned int i = 0; i < handle->size(); ++i)
        collection.emplace_back(handle, i);

    return collection;
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
template<class T>
inline ObjectGetter::CollectionHandle<T> ObjectGetter::GetHandle(CollectionNameMap<T> &collectionNameMap, const std::string &label)
{
    // Try to find the handle in the input map with this label, and return it if it exists
    const auto validLabel = this->GetValidLabel(label);
    const auto iter = collectionNameMap.find(validLabel);
    if (iter != collectionNameMap.end())
        return iter->second;

    // We haven't already got this collection handle, so let's read it from the event and save for future use
    CollectionHandle<T> handle;
    m_pEvent->getByLabel(validLabel, handle);
    collectionNameMap.emplace(validLabel, handle);

    return handle;
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
template<class A, class B>
inline ObjectGetter::PtrVector<A> ObjectGetter::GetManyAssociated(const art::Ptr<B> &object, const CollectionHandle<B> &handle, const std::string &label) const
{
    art::FindManyP<A> association(handle, *m_pEvent, this->GetValidLabel(label));
    return association.at(object.key());
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
template<class A, class B>
inline art::Ptr<A> ObjectGetter::GetSingleAssociated(const art::Ptr<B> &object, const CollectionHandle<B> &handle, const std::string &label) const
{
    const auto associatedObjects = this->GetManyAssociated<A>(object, handle, label);

    const auto nObjects = associatedObjects.size();
    if (nObjects != 1)
        throw cet::exception("ObjectGetter::GetSingleAssociated") << "Found " << nObjects << " associated objects, expected 1" << std::endl;

    return associatedObjects.front();
}

} // namespace ant

#endif // ANATOOL_CORE_OBJECT_GETTER_H
