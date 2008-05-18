/*
============================================================================
 Name        : CS60DbViewView from S60DbViewView.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares view for application.
============================================================================
*/

#ifndef S60DBVIEWVIEW_H
#define S60DBVIEWVIEW_H

// INCLUDES
#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KViewId = {1};

// FORWARD DECLARATIONS
class CS60DbViewContainer;

// CLASS DECLARATION

/**
*  CS60DbViewView view class.
* 
*/
class CS60DbViewView : public CAknView
	{
	public: // Constructors and destructor

		/**
		* EPOC default constructor.
		*/
		void ConstructL();

		/**
		* Destructor.
		*/
		~CS60DbViewView();

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
		CS60DbViewContainer* iContainer;
	};

#endif
