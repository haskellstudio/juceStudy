#pragma once
#include "../JuceLibraryCode/JuceHeader.h"






class TStringLst;
 //static Array<TStringLst*> list;
class TStringLst
{
public:
	virtual Component* createComponent() = 0;
	TStringLst(String &n) : name(n)
	{
		AlphabeticDemoSorter sorter;
		getDemoTypeList().addSorted(sorter, (TStringLst*)this);
	}
	

	struct AlphabeticDemoSorter
	{
		static int compareElements(const TStringLst* first, const TStringLst* second)
		{
			return first->name.compare(second->name);
		}
	};

	static Array<TStringLst*>& getDemoTypeList()
	{
		static Array<TStringLst*> list;
		return list;
	}
	String name;
};



template <class TComponent>
class ComponentList : TStringLst
{
public:
	ComponentList( String & n) : TStringLst(n)
	{
	}

	Component* createComponent() 
	{ 
		return new TComponent();
	}




};




