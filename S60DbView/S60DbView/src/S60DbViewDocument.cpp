/*
============================================================================
 Name        : CS60DbViewDocument from S60DbViewDocument.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : CS60DbViewDocument implementation
============================================================================
*/

// INCLUDE FILES
#include "S60DbViewDocument.h"
#include "S60DbViewAppui.h"

// ================= MEMBER FUNCTIONS =======================

// constructor
CS60DbViewDocument::CS60DbViewDocument(CEikApplication& aApp)
	: CAknDocument(aApp)
	{
	}

// destructor
CS60DbViewDocument::~CS60DbViewDocument()
	{
	}

// EPOC default constructor can leave.
void CS60DbViewDocument::ConstructL()
	{
	}

// Two-phased constructor.
CS60DbViewDocument* CS60DbViewDocument::NewL(
	CEikApplication& aApp) // CS60DbViewApp reference
	{
	CS60DbViewDocument* self = new (ELeave) CS60DbViewDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop();

	return self;
	}
	
// ----------------------------------------------------
// CS60DbViewDocument::CreateAppUiL()
// constructs CS60DbViewAppUi
// ----------------------------------------------------
//
CEikAppUi* CS60DbViewDocument::CreateAppUiL()
	{
	return new (ELeave) CS60DbViewAppUi;
	}
