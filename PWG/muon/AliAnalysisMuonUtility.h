#ifndef ALIANALYSISMUONUTILITY_H
#define ALIANALYSISMUONUTILITY_H

/* $Id: AliAnalysisMuonUtility.h 47782 2011-02-24 18:37:31Z martinez $ */ 

//
// Utilities for muon analysis
//
// Author: Diego Stocco
//

#include "TObject.h"
#include "TString.h"

class TLorentzVector;
class AliInputEventHandler;
class AliVEvent;
class AliMCEvent;
class AliVParticle;
class AliVVertex;
class AliCFGridSparse;

class AliAnalysisMuonUtility : public TObject {
 public:
  
  // Utility methods for CF container
  static Bool_t SetSparseRange(AliCFGridSparse* gridSparse,
                               Int_t ivar, TString labelName,
                               Double_t varMin, Double_t varMax,
                               TString option = "");
  
  // Transparently handle ESD/AOD
  static Bool_t IsAODEvent ( const AliVEvent* event );
  static TString GetFiredTriggerClasses ( const AliVEvent* event );
  static Int_t GetNTracks ( const AliVEvent* event );
  static AliVParticle* GetTrack ( Int_t itrack, const AliVEvent* event );
  
  static Bool_t IsAODTrack ( const AliVParticle* track );
  static Bool_t IsMuonTrack ( const AliVParticle* track );
  static Bool_t IsMuonGhost ( const AliVParticle* track );
  static Double_t GetRabs ( const AliVParticle* track );
  static Double_t GetThetaAbsDeg ( const AliVParticle* track );
  static Int_t GetMatchTrigger ( const AliVParticle* track );
  static Bool_t MatchApt ( const AliVParticle* track ) { return GetMatchTrigger(track) >= 1; }
  static Bool_t MatchLpt ( const AliVParticle* track ) { return GetMatchTrigger(track) >= 2; }
  static Bool_t MatchHpt ( const AliVParticle* track ) { return GetMatchTrigger(track) >= 3; }
  static Double_t GetChi2perNDFtracker ( const AliVParticle* track );
  static Double_t GetXatVertex ( const AliVParticle* track );
  static Double_t GetYatVertex ( const AliVParticle* track );
  static Double_t GetZatVertex ( const AliVParticle* track );
  static Double_t GetXatDCA ( const AliVParticle* track );
  static Double_t GetYatDCA ( const AliVParticle* track );
  static Double_t GetZatDCA ( const AliVParticle* track ) { return GetZatVertex(track); }
  static UInt_t GetMUONTrigHitsMapTrk ( const AliVParticle* track );
  static UInt_t GetMUONTrigHitsMapTrg ( const AliVParticle* track );
  static Int_t GetLoCircuit ( const AliVParticle* track );
  static TLorentzVector GetTrackPair ( const AliVParticle* track1, const AliVParticle* track2 );

  
  // Transparently handle MC
  static Bool_t IsMCEvent ( const AliVEvent* event, const AliMCEvent* mcEvent );
  static Int_t GetNMCTracks ( const AliVEvent* event, const AliMCEvent* mcEvent );
  static AliVParticle* GetMCTrack ( Int_t trackLabel, const AliVEvent* event, const AliMCEvent* mcEvent );
  static Double_t GetMCVertexZ ( const AliVEvent* event, const AliMCEvent* mcEvent );
  
  static Bool_t IsAODMCTrack ( const AliVParticle* mcParticle );
  static Int_t GetMotherIndex ( const AliVParticle* mcParticle );
  static Int_t GetDaughterIndex ( const AliVParticle* mcParticle, Int_t idaughter );
  static Bool_t IsPrimary ( const AliVParticle* mcParticle, const AliMCEvent* mcEvent );
  
  // A useful constant
  static Double_t MuonMass2();
  
  // Transparently handle vertex
  static AliVVertex* GetVertexSPD ( const AliVEvent* event );
  
  // Utilities for ESD/AOD
  static Int_t GetPassNumber ( const AliInputEventHandler* eventHandler );
  static Int_t GetPassNumber ( const char* str );
  
  ClassDef(AliAnalysisMuonUtility, 0);
};

#endif
