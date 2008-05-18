/*
============================================================================
 Name        : CS60DbViewContainer2 from S60DbViewContainer2.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares container control for application.
============================================================================
*/

#ifndef S60DBVIEWCONTAINER2_H
#define S60DBVIEWCONTAINER2_H

// INCLUDES
#include <coecntrl.h>
 
// FORWARD DECLARATIONS
class CEikLabel;        // for example labels

// CLASS DECLARATION

/**
* CS60DbViewContainer2  container control class.
* 
*/
class CS60DbViewContainer2 : public CCoeControl, MCoeControlObserver
	{
	public: // Constructors and destructor
		
		/**
		* EPOC default constructor.
		* @param aRect Frame rectangle for container.
		*/
		void ConstructL(const TRect& aRect);

		/**
		* Destructor.
		*/
		~CS60DbViewContainer2();

	public: // New functions

	public: // Functions from base classes

	private: // Functions from base classes

		/**
		* From CoeControl,SizeChanged.
		*/
		void SizeChanged();

		/**
		* From CoeControl,CountComponentControls.
		*/
		TInt CountComponentControls() const;

		/**
		* From CCoeControl,ComponentControl.
		*/
		CCoeControl* ComponentControl(TInt aIndex) const;

		/**
		* From CCoeControl,Draw.
		*/
		void Draw(const TRect& aRect) const;

		/**
		* From MCoeControlObserver
		* Acts upon changes in the hosted control's state. 
		*
		* @param	aControl	The control changing its state
		* @param	aEventType	The type of control event 
		*/
		void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
		
	private: //data
		
		CEikLabel* iLabel; // example label
		CEikLabel* iToDoLabel; // example label
	};

#endif
