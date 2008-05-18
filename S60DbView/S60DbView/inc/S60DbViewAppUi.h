/*
============================================================================
 Name        : CS60DbViewAppUi from S60DbViewAppui.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares UI class for application.
============================================================================
*/

#ifndef S60DBVIEWAPPUI_H
#define S60DBVIEWAPPUI_H

// INCLUDES
#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>

#include <akntabobserver.h>

// FORWARD DECLARATIONS
class CS60DbViewContainer;


// CLASS DECLARATION

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
* - view architecture
* - status pane
* 
*/
class CS60DbViewAppUi : public CAknViewAppUi, MAknTabObserver
	{
	public: // // Constructors and destructor

		/**
		* EPOC default constructor.
		*/	  
		void ConstructL();

		/**
		* Destructor.
		*/	  
		~CS60DbViewAppUi();
		
	public: // New functions

	public: // Functions from base classes
		/**
		* From MAknTabObserver.
		* @param aIndex tab index
		*/
		void TabChangedL(TInt aIndex);

	private:
		// From MEikMenuObserver
		void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

	private:
		/**
		* From CEikAppUi, takes care of command handling.
		* @param aCommand command to be handled
		*/
		void HandleCommandL(TInt aCommand);

		/**
		* From CEikAppUi, handles key events.
		* @param aKeyEvent Event to handled.
		* @param aType Type of the key event. 
		* @return Response code (EKeyWasConsumed, EKeyWasNotConsumed). 
		*/
		virtual TKeyResponse HandleKeyEventL(
			const TKeyEvent& aKeyEvent,TEventCode aType);

	private: //Data
		CAknNavigationControlContainer* iNaviPane;
		CAknTabGroup* iTabGroup;
		CAknNavigationDecorator* iDecoratedTabGroup;
	};

#endif
