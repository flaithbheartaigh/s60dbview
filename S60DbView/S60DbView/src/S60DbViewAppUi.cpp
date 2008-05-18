/*
============================================================================
 Name        : CS60DbViewAppUi from S60DbViewAppui.cpp
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : CS60DbViewAppUi implementation
============================================================================
*/

// INCLUDE FILES
#include "S60DbViewAppui.h"
#include "S60DbViewView.h"
#include "S60DbViewView2.h"
#include <S60DbView.rsg>
#include "S60DbView.hrh"

#include <avkon.hrh>

// ================= MEMBER FUNCTIONS =======================
//
// ----------------------------------------------------------
// CS60DbViewAppUi::ConstructL()
// 
// ----------------------------------------------------------
//
void CS60DbViewAppUi::ConstructL()
	{
	BaseConstructL();

	// Show tabs for main views from resources
	CEikStatusPane* sp = StatusPane();

	// Fetch pointer to the default navi pane control
	iNaviPane = (CAknNavigationControlContainer*)sp->ControlL( 
		TUid::Uid(EEikStatusPaneUidNavi));

	// Tabgroup has been read from resource and it were pushed to the navi pane. 
	// Get pointer to the navigation decorator with the ResourceDecorator() function. 
	// Application owns the decorator and it has responsibility to delete the object.
	iDecoratedTabGroup = iNaviPane->ResourceDecorator();
	if (iDecoratedTabGroup)
		{
		iTabGroup = (CAknTabGroup*) iDecoratedTabGroup->DecoratedControl();
		iTabGroup->SetObserver( this );
		}

	CS60DbViewView* view1 = new (ELeave) CS60DbViewView;

	CleanupStack::PushL( view1 );
	view1->ConstructL();
	AddViewL( view1 ); // transfer ownership to CAknViewAppUi
	CleanupStack::Pop(); // view1

	CS60DbViewView2* view2 = new (ELeave) CS60DbViewView2;

	CleanupStack::PushL( view2 );
	view2->ConstructL();
	AddViewL( view2 ); // transfer ownership to CAknViewAppUi
	CleanupStack::Pop(); // view2

	SetDefaultViewL(*view1);
	}

// ----------------------------------------------------
// CS60DbViewAppUi::~CS60DbViewAppUi()
// Destructor
// Frees reserved resources
// ----------------------------------------------------
//
CS60DbViewAppUi::~CS60DbViewAppUi()
	{
	delete iDecoratedTabGroup;
	}

// ------------------------------------------------------------------------------
// CS60DbViewAppUi::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
//  This function is called by the EIKON framework just before it displays
//  a menu pane. Its default implementation is empty, and by overriding it,
//  the application can set the state of menu items dynamically according
//  to the state of application data.
// ------------------------------------------------------------------------------
//
void CS60DbViewAppUi::DynInitMenuPaneL(
	TInt /*aResourceId*/,CEikMenuPane* /*aMenuPane*/)
	{
	}

// ----------------------------------------------------
// CS60DbViewAppUi::HandleKeyEventL(
//	 const TKeyEvent& aKeyEvent,TEventCode /*aType*/)
// takes care of key event handling
// ----------------------------------------------------
//
TKeyResponse CS60DbViewAppUi::HandleKeyEventL(
	const TKeyEvent& aKeyEvent,TEventCode aType)
	{
	if ( iTabGroup == NULL )
		{
		return EKeyWasNotConsumed;
		}

	if ( aKeyEvent.iCode == EKeyLeftArrow || aKeyEvent.iCode == EKeyRightArrow )
		{
		return iTabGroup->OfferKeyEventL( aKeyEvent, aType );
		}
	else
		{
		return EKeyWasNotConsumed;
		}
	}

// ----------------------------------------------------
// CS60DbViewAppUi::HandleCommandL(TInt aCommand)
// takes care of command handling
// ----------------------------------------------------
//
void CS60DbViewAppUi::HandleCommandL(TInt aCommand)
	{
	switch ( aCommand )
		{
		case EEikCmdExit:
			{
			Exit();
			break;
			}
		case ES60DbViewCmdAppTest:
			{
			iEikonEnv->InfoMsg(_L("test"));
			break;
			}
		// TODO: Add Your command handling code here

		default:
			break; 
		}
	}

 // ----------------------------------------------------
 // CS60DbViewAppUi::TabChangedL(TInt aIndex)
 // This method gets called when CAknTabGroup active 
 // tab has changed.
 // ----------------------------------------------------
 //
 void CS60DbViewAppUi::TabChangedL(TInt aIndex)
	{
	ActivateLocalViewL(TUid::Uid(iTabGroup->TabIdFromIndex(aIndex)));
	}
