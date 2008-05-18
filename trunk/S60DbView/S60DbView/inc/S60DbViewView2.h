/*
============================================================================
 Name        : CS60DbViewView2 from S60DbViewView2.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares view for application.
============================================================================
*/

#ifndef S60DBVIEWVIEW2_H
#define S60DBVIEWVIEW2_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KView2Id = {2};

// FORWARD DECLARATIONS
class CS60DbViewContainer2;

// CLASS DECLARATION

/**
*  CS60DbViewView2 view class.
* 
*/
class CS60DbViewView2 : public CAknView
	{
	public: // Constructors and destructor

		/**
		* EPOC default constructor.
		*/
		void ConstructL();

		/**
		* Destructor.
		*/
		~CS60DbViewView2();

	public: // Functions from base classes

		/**
		* From CAknView returns Uid of View
		* @return TUid uid of the view
		*/
		TUid Id() const;

		/**
		* From MEikMenuObserver delegate commands from the menu
		* @param aCommand a command emitted by the menu 
		* @return void
		*/
		void HandleCommandL(TInt aCommand);

		/**
		* From CAknView reaction if size change
		* @return void
		*/
		void HandleClientRectChange();

	private:

		/**
		* From CAknView activate the view
		* @param aPrevViewId 
		* @param aCustomMessageId 
		* @param aCustomMessage 
		* @return void
		*/
		void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,
			const TDesC8& aCustomMessage);

		/**
		* From CAknView deactivate the view (free resources)
		* @return void
		*/
		void DoDeactivate();

	private: // Data
		CS60DbViewContainer2* iContainer;
	};

#endif
