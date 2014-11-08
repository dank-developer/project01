/**************************************************************************
 * CS1C Class Project
 * -----------------------------------------------------------------------
 * Product Class Test
 * -----------------------------------------------------------------------
 * Version: 0.0.1
 * -----------------------------------------------------------------------
 * Programmers:
 *		Austin 	Vaday
 *		Anthony Ramirez
 *		Annie	Raichev
 *		Erik 	Karlsson
 *
 *************************************************************************/


#ifndef PRODUCTCLASSHEADER_H_
#define PRODUCTCLASSHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "List.h"

using namespace std;

/***********************************************************
 * PARSE CODE - GLOBAL CONSTANT
 * ---------------------------------------------------------
 *
 * Sets the parse code required to create each specification
 * 	Used to check for each specification in the string.
 *
 ********** -> MUST BE 3 CHARACTERS LONG <- ****************/

const string PARSE_CODE = "N$P";

/***********************************************************/


/**************************************************************************
 * Product Class
 * -----------------------------------------------------------------------
 * Product class will be used to store data of each current product that is
 * 	available for sale by Extreme Robot Cat Coderz. The class will
 *
 *************************************************************************/
class Product
{
	public:
		Product();
		// Default Constructor

		Product(float  cost,		// Starting cost of product
				string name,		// Starting name of product
				string description,	// Description of the product
				string specs); 		// Specifications of the product

				/***********-> SPECIAL NOTE ABOUT SPECIFICATION <-*********
				*
				* Temporary:
				*	The string that will be passed into specifications will
				*	be required to have a special character to signify the
				*   separation of each specification
				*
				* Note from Erik:
				*	This is how we will be dealing with this for now, we
				*	might not even end up using this functionality. If that
				*	ends up being the case we will delete this portion of
				*	the code.
				*
				*	I would just rather be safe than sorry!
				*
				*
				**********-> SPECIAL NOTE ABOUT SPECIFICATION <-*********/

		// Non-default Constructor
		//	Pass in: Cost, name, description and the specifications

		~Product();
		// Deconstructor

		/*****************************************************************
		 * Mutators
		 ****************************************************************/

		void changeCost(float  newCost);
		// Changes cost of the product
		//	Passes in a new float value of product and modifies the
		//	cost member of the class.
		// Returns: Nothing

		void changeName(string newName);
		// Changes the name of the product.
		//	Passes in a new string to replace the productName string
		//	value of the class.
		// Returns: Nothing

		void changeDescription(string description);
		// Changes the description of the product
		//	Passes in a new string to replace the productDescription
		//	string value of the class.
		// Returns: Nothing

		void addSpec(string newSpec);
		// Adds a new specification to the product
		//	Passes in a new string to add to the current list of
		//	specifications
		// Returns: Nothing

		void removeSpec();
		// Removes a specification from the product
		//	Will display all specifications of the product and the user
		//	can choose which specification that they want to remove.
		// Returns: Nothing

		void modifySpec();
		// Modifies one specification detail of the product
		//	Displays all current specifications of the product. Prompts
		//	the user to select which specification to modify and allows
		//	the user to enter a new specification as string.
		// Returns: Nothing


		/*****************************************************************
		 * Accessors
		 ****************************************************************/
		float getCost() const;
		// Returns the cost of the product

		string getName() const;
		// Returns the name of the product

		string getDescription() const;
		// Returns the description of the product

		string getSingleSpec(int specNumber) const;
		// Returns a single specification of the product
		//

		string getAllSpecs() const;
		// Returns the specifications of the product
		//	This method will return the specifications as a single string.

		int getModelNumber() const;
		// Returns the model number of the product
		//	This method will return the model number of the product as an
		//	integer

		int getReleaseDate() const;
		// Returns the date of release of the product
		//	This method will return an integer that represents the date
		//	the product was released to the public

	private:
		// Data members
		float		 cost;					// Cost of the product
		string  	 productName;			// Name of the product
		string		 productDescription;	// Description of the product
		List<string> productSpecs;			// A queue of the product's
											//	specifications
		int			 modelNumber;			// Model number of the product
		int			 dateReleased;			// Stores the date the product
											//	was released
		int			 specCounter;			// Keeps a running total of
											//	specs
		// Class Helper Function
		// 	Creates the list of specifications
		//		User will pass in a string with the characters N$P to
		//		separate each spec from the next.
		void createSpecList(string specs)
		{
			int		enqueueIndex;
			int		stringIndex;
			string 	enqueueSpecString;

			enqueueIndex = 0;

			// Iterates through the specification string and creates a
			//	list of specifications
			for(stringIndex = 0;
				stringIndex == signed(specs.length());
				stringIndex ++)
			{

				// Checks if the string is nearing the end of the list
				//	If not it will check if the current and next 3 char
				//	match the parsing code required to add to the queue
				if(stringIndex + 3 < signed(specs.length()))
				{

					// Checks against the parsing code
					if(specs[stringIndex] 	  == PARSE_CODE[0]
					&& specs[stringIndex + 1] == PARSE_CODE[1]
					&& specs[stringIndex + 2] == PARSE_CODE[2])
					{
						// Enqueues the current specification
						productSpecs.Enqueue(enqueueSpecString);

						// Compensates for the the parsing code
						stringIndex  = stringIndex + 3;

						// Reinitializes the enqueue index to begin at
						//	the first index of the string
						enqueueIndex = 0;

					}// END INNER IF

				} // END OUTER IF

				// Checks if it has reached the end of the specification
				//	string
				else if (stringIndex == signed(specs.length()))
				{
					productSpecs.Enqueue(enqueueSpecString);

				} // END ELSE IF

				// Adds each character as the spec string is iterated
				//	through
				enqueueSpecString[enqueueIndex] = specs[stringIndex];

				enqueueIndex = enqueueIndex + 1;

			} // END FOR LOOP

		} // END METHOD
};


#endif /* PRODUCTCLASSHEADER_H_ */