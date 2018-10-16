#include "anatool/Core/ObjectGetter.h"

namespace ant
{

PFParticleVector ObjectGetter::GetPFParticles(const std::string &label)
{
    return this->GetCollection(m_pfParticleCollections, label); 
}

// -----------------------------------------------------------------------------------------------------------------------------------------

ClusterVector ObjectGetter::GetAssociatedClusters(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    return this->GetManyAssociated<recob::Cluster>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel);
}

// -----------------------------------------------------------------------------------------------------------------------------------------

SpacePointVector ObjectGetter::GetAssociatedSpacePoints(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    return this->GetManyAssociated<recob::SpacePoint>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel);
}

// -----------------------------------------------------------------------------------------------------------------------------------------

Vertex_p ObjectGetter::GetAssociatedVertex(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    return this->GetSingleAssociated<recob::Vertex>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel);
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
HitVector ObjectGetter::GetAssociatedHits(const Cluster_p &cluster, const std::string &clusterLabel, const std::string &associationLabel)
{
    return this->GetManyAssociated<recob::Hit>(cluster, this->GetHandle(m_clusterCollections, clusterLabel), associationLabel);
}

// -----------------------------------------------------------------------------------------------------------------------------------------

Hit_p ObjectGetter::GetAssociatedHit(const SpacePoint_p &spacePoint, const std::string &spacePointLabel, const std::string &associationLabel)
{
    return this->GetSingleAssociated<recob::Hit>(spacePoint, this->GetHandle(m_spacePointCollections, spacePointLabel), associationLabel);
}

} // namespace ant
