/*
============================================================================
 Name        : CS60DbViewApp from S60DbViewApp.cpp
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Main application class
============================================================================
*/

// INCLUDE FILES
#include    "S60DbViewApp.h"
#include    "S60DbViewDocument.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CS60DbViewApp::AppDllUid()
// Returns application UID
// ---------------------------------------------------------
//
TUid CS60DbViewApp::AppDllUid() const
	{
	return KUidS60DbView;
	}

// ---------------------------------------------------------
// CS60DbViewApp::CreateDocumentL()
// Creates CS60DbViewDocument object
// ---------------------------------------------------------
//
CApaDocument* CS60DbViewApp::CreateDocumentL()
	{
	return CS60DbViewDocument::NewL( *this );
	}

// ================= OTHER EXPORTED FUNCTIONS ==============
//
// ---------------------------------------------------------
// NewApplication() 
// Constructs CS60DbViewApp
// Returns: created application object
// ---------------------------------------------------------
//
EXPORT_C CApaApplication* NewApplication()
	{
	return new CS60DbViewApp;
	}

// ---------------------------------------------------------
// E32Dll(TDllReason) 
// Entry point function for EPOC Apps
// Returns: KErrNone: No error
// ---------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason )
	{
	return KErrNone;
	}
