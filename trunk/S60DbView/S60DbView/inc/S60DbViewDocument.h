/*
============================================================================
 Name        : CS60DbViewDocument from S60DbViewDocument.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares document for application.
============================================================================
*/

#ifndef S60DBVIEWDOCUMENT_H
#define S60DBVIEWDOCUMENT_H

// INCLUDES
#include <akndoc.h>
   
// CONSTANTS

// FORWARD DECLARATIONS
class CEikAppUi;

// CLASS DECLARATION

/**
*  CS60DbViewDocument application class.
*/
class CS60DbViewDocument : public CAknDocument
	{
	public: // Constructors and destructor
		/**
		* Two-phased constructor.
		*/
		static CS60DbViewDocument* NewL(CEikApplication& aApp);

		/**
		* Destructor.
		*/
		virtual ~CS60DbViewDocument();

	public: // New functions

	public: // Functions from base classes
	protected:  // New functions

	protected:  // Functions from base classes

	private:

		/**
		* EPOC default constructor.
		*/
		CS60DbViewDocument(CEikApplication& aApp);
		void ConstructL();

	private:

		/**
		* From CEikDocument, create CS60DbViewAppUi "App UI" object.
		*/
		CEikAppUi* CreateAppUiL();
	};

#endif
