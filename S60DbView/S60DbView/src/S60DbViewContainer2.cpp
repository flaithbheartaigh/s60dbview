/*
============================================================================
 Name        : CS60DbViewContainer2 from S60DbViewContainer2.cpp
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Container control implementation
============================================================================
*/

// INCLUDE FILES
#include "S60DbViewContainer2.h"

#include <eiklabel.h>  // for example label control


// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CS60DbViewContainer2::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CS60DbViewContainer2::ConstructL(const TRect& aRect)
	{
	CreateWindowL();

	iLabel = new (ELeave) CEikLabel;
	iLabel->SetContainerWindowL( *this );
	iLabel->SetTextL( _L("Example View 2") );

	iToDoLabel = new (ELeave) CEikLabel;
	iToDoLabel->SetContainerWindowL( *this );
	iToDoLabel->SetTextL( _L("Add Your controls\n here") );

	SetRect(aRect);
	ActivateL();
	}

// Destructor
CS60DbViewContainer2::~CS60DbViewContainer2()
	{
	delete iLabel;
	delete iToDoLabel;
	}

// ---------------------------------------------------------
// CS60DbViewContainer2::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CS60DbViewContainer2::SizeChanged()
	{
	// TODO: Add here control resize code etc.
	iLabel->SetExtent( TPoint(10,10), iLabel->MinimumSize() );
	iToDoLabel->SetExtent( TPoint(10,100), iToDoLabel->MinimumSize() );
	}

// ---------------------------------------------------------
// CS60DbViewContainer2::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CS60DbViewContainer2::CountComponentControls() const
	{
	return 2; // return nbr of controls inside this container
	}

// ---------------------------------------------------------
// CS60DbViewContainer2::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CS60DbViewContainer2::ComponentControl(TInt aIndex) const
	{
	switch ( aIndex )
		{
		case 0:
			return iLabel;
		case 1:
			return iToDoLabel;
		default:
			return NULL;
		}
	}

// ---------------------------------------------------------
// CS60DbViewContainer2::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CS60DbViewContainer2::Draw(const TRect& aRect) const
	{
	CWindowGc& gc = SystemGc();
	// TODO: Add your drawing code here
	// example code...
	gc.SetPenStyle( CGraphicsContext::ENullPen );
	gc.SetBrushColor( KRgbGray );
	gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
	gc.DrawRect( aRect );
	}

// ---------------------------------------------------------
// CS60DbViewContainer2::HandleControlEventL(
//	 CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CS60DbViewContainer2::HandleControlEventL(
	CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
	{
	// TODO: Add your control event handler code here
	}
