#pragma once
#include "../JuceLibraryCode/JuceHeader.h"


class TStringLst
{
public:
	virtual Component* createComponent() = 0;
	TStringLst(String &n) : name(n)
	{
		getDemoTypeList().set(n, (TStringLst*)this);

	}


	static HashMap <String, TStringLst*>& getDemoTypeList()
	{
		static HashMap <String, TStringLst*> list;
		//static Array<TStringLst*> list;
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
