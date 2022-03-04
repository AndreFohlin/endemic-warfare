#include "Highscore.h"

Highscore::Highscore(void)
{
	listElements = 10;
}

Highscore::~Highscore(void)
{
}

void Highscore::CreateHighscore(std::string fileName, int listSize)
{
	listElements = listSize;

	TiXmlDocument	highscoreXML;

	xmlPath = fileName;

	// -Create & Link Root Node
	TiXmlElement * root = new TiXmlElement( "ROOT" );  
	highscoreXML.LinkEndChild( root );  

	// -ListElement 
	TiXmlElement *listElement[50];

	for(int i = 0; i < listSize; i++)
	{
		// -List Element Name
		std::string player = "Highscore";

		// -Creates a new list element
		listElement[i] = new TiXmlElement( player.c_str() );

		// -Set Name Attribute
		std::string name = "Name";
		listElement[i]->SetAttribute( name.c_str(), " " );

		// -Set Score Attribute
		std::string score = "Score";
		listElement[i]->SetAttribute( score.c_str(), " " );

		// -Link all ListElements
		root->LinkEndChild( listElement[i] );
	}

	// -Save To File
	highscoreXML.SaveFile(fileName.c_str());
}

void Highscore::AddToHighscore(std::string name, int score)
{
	// -Load file
	if(highscoreDoc.LoadFile( xmlPath.c_str() ))
	{
		TiXmlElement		*DataElement = NULL;
  		TiXmlAttribute		*DataAttribute = NULL;
		TiXmlAttribute		*ScoreAttribute = NULL;

		// -Get root element's firts child
		DataElement = highscoreDoc.RootElement()->FirstChildElement();

		// -Check if score more or equal another score
		for(int i = listElements; i <= 0; i--)
		{

			// -Set value of first attribute to the new Name
			DataElement->FirstAttribute()->SetValue( name.c_str() );

			// -Set value of secon attribute to the new Score
			char buffer[10];
			//ScoreAttribute->SetValue(itoa(score, buffer, 10));

			// -Exit loop
			i += listElements;

			// -Go to next data element
			DataElement = DataElement->NextSiblingElement();
		}

		// -Save to file
		highscoreDoc.SaveFile( xmlPath.c_str());

	}
	else
	{
		// -If failed to load
		std::cout << "error" << std::endl;
	}
}

void Highscore::ReadHighscore(std::string fileName)
{
	// -Load highscore file
	if(highscoreDoc.LoadFile( fileName.c_str() ))
	{
		TiXmlElement		*DataElement = NULL;
		TiXmlAttribute		*DataAttribute = NULL;

		// -Set first child element of root node
		DataElement = highscoreDoc.RootElement()->FirstChildElement();

		// -Read the first element
		for(int i = 0; i < listElements; i++)
		{
			DataAttribute = DataElement->FirstAttribute();
			
			// -Read First Attribute
			listName[i] = DataAttribute->Value();

			DataAttribute = DataAttribute->Next();

			// -Read Second Attribute
			listScore[i] = int(atoi( DataAttribute->Value() ));

			DataElement = DataElement->NextSiblingElement();
		}
	}
	else
	{
		// -If failed to load file
		std::cout << "Error Loading File: " << xmlPath.c_str() << std::endl;
	}

	// -Draw Elements in highscore list
	for(int i = 0; i < listElements; i++)
	{
		std::cout << listName[i].c_str() << " " << listScore[i] << std::endl;
	}
}
