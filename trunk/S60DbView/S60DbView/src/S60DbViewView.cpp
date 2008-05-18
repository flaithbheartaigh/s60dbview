/*
============================================================================
 Name        : CS60DbViewView from S60DbViewView.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : CS60DbViewView implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <S60DbView.rsg>
#include  "S60DbViewView.h"
#include  "S60DbViewContainer.h" 

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CS60DbViewView::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CS60DbViewView::ConstructL()
	{
	BaseConstructL( R_S60DBVIEW_VIEW1 );
	}

// ---------------------------------------------------------
// CS60DbViewView::~CS60DbViewView()
// destructor
// ---------------------------------------------------------
//
CS60DbViewView::~CS60DbViewView()
	{
	if ( iContainer )
		{
		AppUi()->RemoveFromViewStack( *this, iContainer );
		}

	delete iContainer;
	}

// ---------------------------------------------------------
// TUid CS60DbViewView::Id()
//
// ---------------------------------------------------------
//
TUid CS60DbViewView::Id() const
	{
	return KViewId;
	}

// ---------------------------------------------------------
// CS60DbViewView::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CS60DbViewView::HandleCommandL(TInt aCommand)
	{   
	switch ( aCommand )
		{
		case EAknSoftkeyOk:
			{
			iEikonEnv->InfoMsg( _L("view1 ok") );
			break;
			}
		case EAknSoftkeyBack:
			{
			AppUi()->HandleCommandL(EEikCmdExit);
			break;
			}
		default:
			{
			AppUi()->HandleCommandL( aCommand );
			break;
			}
		}
	}

// ---------------------------------------------------------
// CS60DbViewView::HandleClientRectChange()
// ---------------------------------------------------------
//
void CS60DbViewView::HandleClientRectChange()
	{
	if ( iContainer )
		{
		iContainer->SetRect( ClientRect() );
		}
	}

// ---------------------------------------------------------
// CS60DbViewView::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CS60DbViewView::DoActivateL(
	const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
	const TDesC8& /*aCustomMessage*/)
	{
	if (!iContainer)
		{
		iContainer = new (ELeave) CS60DbViewContainer;
		iContainer->SetMopParent(this);
		iContainer->ConstructL( ClientRect() );
		AppUi()->AddToStackL( *this, iContainer );
		} 
	}

// ---------------------------------------------------------
// CS60DbViewView::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CS60DbViewView::DoDeactivate()
	{
	if ( iContainer )
		{
		AppUi()->RemoveFromViewStack( *this, iContainer );
		}
	
	delete iContainer;
	iContainer = NULL;
	}
