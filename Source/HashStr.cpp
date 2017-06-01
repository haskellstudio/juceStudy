#include "HashStr.h"

#include "../JuceLibraryCode/JuceHeader.h"

HashStr::HashStr()
{
	HashMap<int, String> hash;
	hash.set(1, "item1");
	hash.set(2, "item2");
	//DBG(hash[1]); // prints "item1"

	HashMap <String, int> hs;
	hs.set("name", 123);
	hs.set("some", 234);
//	String s (hs["name"]);
	DBG(hs["name"] );
}


HashStr::~HashStr()
{
}


static HashStr hs;