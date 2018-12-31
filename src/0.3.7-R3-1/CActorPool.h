/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#include "common.h"
#include "CVector.h"
#include "CActor.h"

#define MAX_ACTORS 1000

SAMP_BEGIN

struct SAMP_API ActorInfo {
	ID			m_nId;
	int		m_nModel;
	CVector	m_position;
	float		m_fRotation;
	float		m_fHealth;
	bool		m_bInvulnerable;
};

class SAMP_API CActorPool {
public:
	int			m_nLargestId;
	CActor	  *m_pObject[MAX_ACTORS];
	BOOL			m_bNotEmpty[MAX_ACTORS];
	::CPed	  *m_pGameObject[MAX_ACTORS];
	int			pad_2ee4[MAX_ACTORS];
	int			pad_3e84[MAX_ACTORS];

	CActorPool();
	~CActorPool();
	
	CActor *GetObject(ID nId);
	BOOL DoesExist(ID nId);
	void UpdateLargestId();
	BOOL Delete(ID nId);
	ID Find(::CPed *pGamePed);
	BOOL Create(ActorInfo *pInfo);
};

SAMP_END