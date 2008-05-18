/*
============================================================================
 Name        : CS60DbViewApp from S60DbViewApp.h
 Author      : ioernt
 Version     :
 Copyright   : ioerntLoveQiQi
 Description : Declares main application class.
============================================================================
*/

#ifndef S60DBVIEWAPP_H
#define S60DBVIEWAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidS60DbView = { 0x0e5e58da };

// CLASS DECLARATION

/**
* CS60DbViewApp application class.
* Provides factory to create concrete document object.
* 
*/
class CS60DbViewApp : public CAknApplication
	{
	
	public: // Functions from base classes
	private:

		/**
		* From CApaApplication, creates CS60DbViewDocument document object.
		* @return A pointer to the created document object.
		*/
		CApaDocument* CreateDocumentL();
		
		/**
		* From CApaApplication, returns application's UID (KUidS60DbView).
		* @return The value of KUidS60DbView.
		*/
		TUid AppDllUid() const;
	};

#endif
