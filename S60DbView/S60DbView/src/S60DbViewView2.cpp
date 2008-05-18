/*
============================================================================
 Name        : CS60DbViewView2 from S60DbViewView2.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : CS60DbViewView2 implementation
============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <S60DbView.rsg>
#include  "S60DbViewView2.h"
#include  "S60DbViewContainer2.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CS60DbViewView2::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CS60DbViewView2::ConstructL()
	{
	BaseConstructL( R_S60DBVIEW_VIEW2 );
	}

// ---------------------------------------------------------
// CS60DbViewView2::~CS60DbViewView2()
// destructor
// ---------------------------------------------------------
//
CS60DbViewView2::~CS60DbViewView2()
	{
	if ( iContainer )
		{
		AppUi()->RemoveFromViewStack( *this, iContainer );
		}

	delete iContainer;
	}

// ---------------------------------------------------------
// TUid CS60DbViewView2::Id()
// 
// ---------------------------------------------------------
//
TUid CS60DbViewView2::Id() const
	{
	return KView2Id;
	}

// ---------------------------------------------------------
// CS60DbViewView2::HandleCommandL(TInt aCommand)
// takes care of view command handling
// ---------------------------------------------------------
//
void CS60DbViewView2::HandleCommandL(TInt aCommand)
	{
	switch ( aCommand )
		{
		case EAknSoftkeyOk:
			{
			iEikonEnv->InfoMsg( _L("view2 ok") );
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
// CS60DbViewView2::HandleClientRectChange()
// ---------------------------------------------------------
//
void CS60DbViewView2::HandleClientRectChange()
	{
	if ( iContainer )
		{
		iContainer->SetRect( ClientRect() );
		}
	}

// ---------------------------------------------------------
// CS60DbViewView2::DoActivateL(...)
// 
// ---------------------------------------------------------
//
void CS60DbViewView2::DoActivateL(
	const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
	const TDesC8& /*aCustomMessage*/)
	{
	if (!iContainer)
		{
		iContainer = new (ELeave) CS60DbViewContainer2;
		iContainer->SetMopParent(this);
		iContainer->ConstructL( ClientRect() );
		AppUi()->AddToStackL( *this, iContainer );
		}
   }

// ---------------------------------------------------------
// CS60DbViewView2::DoDeactivate()
// 
// ---------------------------------------------------------
//
void CS60DbViewView2::DoDeactivate()
	{
	if ( iContainer )
		{
		AppUi()->RemoveFromViewStack( *this, iContainer );
		}
	
	delete iContainer;
	iContainer = NULL;
	}
