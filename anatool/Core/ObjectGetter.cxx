#include "anatool/Core/ObjectGetter.h"

namespace ant
{
    
ObjectGetter::ObjectGetter(const art::Event *pEvent, const std::string &defaultLabel) : 
    m_pEvent(pEvent),
    m_defaultLabel(defaultLabel)
{
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
std::string ObjectGetter::GetValidLabel(const std::string &label) const
{
    return label.empty() ? m_defaultLabel : label;
}

// -----------------------------------------------------------------------------------------------------------------------------------------

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
    
bool ObjectGetter::HasAssociatedTrack(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    const auto nTracks = this->GetManyAssociated<recob::Track>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel).size();

    if (nTracks > 1)
        throw cet::exception("ObjectGetter::HasAssociatedTrack") << "PFParticle has more than 1 track associated!" << std::endl;

    return (nTracks != 0);
}

// -----------------------------------------------------------------------------------------------------------------------------------------
    
bool ObjectGetter::HasAssociatedShower(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    const auto nShowers = this->GetManyAssociated<recob::Shower>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel).size();

    if (nShowers > 1)
        throw cet::exception("ObjectGetter::HasAssociatedShower") << "PFParticle has more than 1 shower associated!" << std::endl;

    return (nShowers != 0);
}

// -----------------------------------------------------------------------------------------------------------------------------------------

Track_p ObjectGetter::GetAssociatedTrack(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    return this->GetSingleAssociated<recob::Track>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel);
}

// -----------------------------------------------------------------------------------------------------------------------------------------

Shower_p ObjectGetter::GetAssociatedShower(const PFParticle_p &particle, const std::string &pfParticleLabel, const std::string &associationLabel)
{
    return this->GetSingleAssociated<recob::Shower>(particle, this->GetHandle(m_pfParticleCollections, pfParticleLabel), associationLabel);
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
