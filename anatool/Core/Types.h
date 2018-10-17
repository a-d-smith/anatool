/**
 *  @file
 *
 *  @brief  Header file containing useful typedefs
 */

#ifndef ANATOOL_TYPES_H
#define ANATOOL_TYPES_H

#include <vector>
#include <unordered_map>

#include "canvas/Persistency/Common/Ptr.h"

#include "lardataobj/RecoBase/Hit.h"
#include "lardataobj/RecoBase/PFParticle.h"
#include "lardataobj/RecoBase/Cluster.h"
#include "lardataobj/RecoBase/SpacePoint.h"
#include "lardataobj/RecoBase/Vertex.h"
#include "lardataobj/RecoBase/Track.h"
#include "lardataobj/RecoBase/Shower.h"

namespace ant
{

// Ptr to various types
typedef art::Ptr< recob::Hit >         Hit_p;
typedef art::Ptr< recob::PFParticle >  PFParticle_p;
typedef art::Ptr< recob::Cluster >     Cluster_p;
typedef art::Ptr< recob::SpacePoint >  SpacePoint_p;
typedef art::Ptr< recob::Vertex >      Vertex_p;
typedef art::Ptr< recob::Track >       Track_p;
typedef art::Ptr< recob::Shower >      Shower_p;

// Collections
typedef std::vector<Hit_p>         HitVector;
typedef std::vector<PFParticle_p>  PFParticleVector;
typedef std::vector<Cluster_p>     ClusterVector;
typedef std::vector<SpacePoint_p>  SpacePointVector;
typedef std::vector<Vertex_p>      VertexVector;
typedef std::vector<Track_p>       TrackVector;
typedef std::vector<Shower_p>      ShowerVector;

// Associations
typedef std::unordered_map<PFParticle_p, HitVector>         PFParticleToHits;
typedef std::unordered_map<PFParticle_p, ClusterVector>     PFParticleToClusters;
typedef std::unordered_map<PFParticle_p, SpacePointVector>  PFParticleToSpacePoints;
typedef std::unordered_map<PFParticle_p, Vertex_p>          PFParticleToVertex;
typedef std::unordered_map<PFParticle_p, Track_p>           PFParticleToTrack;
typedef std::unordered_map<PFParticle_p, Shower_p>          PFParticleToShower;
typedef std::unordered_map<Cluster_p, HitVector>            ClusterToHits;
typedef std::unordered_map<SpacePoint_p, Hit_p>             SpacePointToHit;
typedef std::unordered_map<Track_p, HitVector>              TrackToHits;
typedef std::unordered_map<Shower_p, HitVector>             ShowerToHits;

} // namespace ant

#endif // ANATOOL_TYPES_H
