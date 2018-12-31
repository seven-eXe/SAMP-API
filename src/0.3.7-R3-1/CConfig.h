/*
	This is a SAMP (0.3.7-R3) API project file.
	Developer: LUCHARE <luchare.dev@gmail.com>
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#include "common.h"

SAMP_BEGIN

enum ValueType {
	None,
	Int,
	String,
	Float
};

class SAMP_API CConfig {
public:
	struct SAMP_API Entry {
		char			m_szName[41];
		BOOL			m_bReadOnly; // maybe
		ValueType	m_nType;
		int			m_nValue;
		float			m_fValue;
		char		  *m_szValue;
	}	  m_entry[512];
	
	BOOL m_bNotEmpty[512]; // map
	char m_szFilename[261];
	int  m_nFirstFree;

	CConfig(const char *szFile);
	~CConfig();

	void FindFirstFree();
	int GetIndex(const char *szEntry);
	bool DoesExist(const char *szEntry);
	int CreateEntry(const char *szName);
	int GetIntValue(const char *szEntry);
	const char *GetStringValue(const char *szEntry);
	float GetFloatValue(const char *szEntry);
	BOOL Free(const char *szEntry);
	int GetValueType(const char *szEntry);
	Entry *GetEntry(int nIndex);
	int GetType(const char *szString);
	BOOL Save();
	BOOL WriteIntValue(const char *szEntry, int nValue, BOOL bReadOnly = 0);
	BOOL WriteStringValue(const char *szEntry, const char *szValue, BOOL bReadOnly = 0);
	BOOL WriteFloatValue(const char *szEntry, float fValue, BOOL bReadOnly = 0);
	void Write(const char *szEntry, char *szBuffer);
	BOOL Load();
};

extern CConfig *&pConfig;

SAMP_END