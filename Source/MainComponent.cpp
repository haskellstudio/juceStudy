/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/



#include "ComponentList.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
#include "NewComponent.h"



class MainContentComponent   : public Component
	, public ListBoxModel
{
public:

	//ScopedPointer<Component> currentDemo;
	bool keyPressed(const KeyPress& key) override
	{
		//[UserCode_keyPressed] -- Add your code here...

		DBG("MainContentComponent keyPressed");
		return false;
	}

	ListBox _listBox;

	ScopedPointer<Component> currentDemo;

	int currentIndex;
    //==============================================================================
    MainContentComponent()
    {
		//setOpaque(true);
	
      setSize (800, 600);
	  _listBox.setModel(this);



	  addAndMakeVisible(_listBox);
	  _listBox.setName("_listBox");


	  TStringLst * s = TStringLst::getDemoTypeList()["ShaderEditor"];
	  if (s)
	  {
		  currentDemo = nullptr;
		  currentDemo = s->createComponent();
		  addAndMakeVisible(currentDemo);
		  currentIndex = 0;
	  }
	  resized();
    }

    ~MainContentComponent()
    {
		//currentDemo = nullptr;
    }

	void paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected) override
	{

		if (rowIsSelected)
			g.fillAll(Colours::deepskyblue);

		HashMap <String, TStringLst*>& hm = TStringLst::getDemoTypeList();

		int count = 0;
		for (HashMap<String, TStringLst*>::Iterator i(hm); i.next();)
		{
			if (rowNumber == count)
			{
				AttributedString a;
				a.setJustification(Justification::centredLeft);


				a.append(i.getKey(), Font(20.0f), Colours::white);

				a.draw(g, Rectangle<int>(width + 10, height).reduced(6, 0).toFloat());
			}
			count++;
			//if()
		}
			
			//DBG( << " -> " << i.getValue());
	}


	void selectedRowsChanged(int lastRowSelected) override
	{
		if (currentIndex == lastRowSelected)
		{
			return;
		}
		currentIndex = lastRowSelected;
		HashMap <String, TStringLst*>& hm = TStringLst::getDemoTypeList();

		int count = 0;
		for (HashMap<String, TStringLst*>::Iterator i(hm); i.next();)
		{
			if (lastRowSelected == count)
			{
				String ts = i.getKey();
				TStringLst * s = TStringLst::getDemoTypeList()[i.getKey()];
				if (s)
				{
					currentDemo = nullptr;
					currentDemo = s->createComponent();
					addAndMakeVisible(currentDemo);
				}
				resized();
			}
			count++;
		}
	}



    void paint (Graphics& g) override
    {
	//	
        // You can add your component specific drawing code here!
        // This will draw over the top of the openGL background.
    }
	int getNumRows() override
	{
		int i = TStringLst::getDemoTypeList().size();
		return  TStringLst::getDemoTypeList().size();
	}
    void resized() override
    {
		auto r = getLocalBounds();
		int listBoxWidth = roundToInt(proportionOfWidth(0.2000f));
		_listBox.setBounds(r.removeFromLeft(listBoxWidth));
	
		FlexBox masterbox;
		masterbox.flexDirection = FlexBox::Direction::column;// column;// : FlexBox::Direction::row;
		masterbox.alignItems = FlexBox::AlignItems::stretch;
		masterbox.alignContent = FlexBox::AlignContent::stretch;
		masterbox.flexWrap = juce::FlexBox::Wrap::wrap;
		masterbox.justifyContent = FlexBox::JustifyContent::center;
		


		int num = getNumChildComponents();
		for (auto i = 0; i < num; i++)
		{
			auto c = getChildComponent(i);
			if (c->getName() == "_listBox")
				continue;
			if (c)
			{
				masterbox.items.add(FlexItem(1, 1).withFlex(1).withMargin(10));
				auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
				flexitem.associatedComponent = c;
			}
		}
		//Rectangle<float> r = getLocalBounds().toFloat();
		//r.reduce(10.0f, 10.0f);
		masterbox.performLayout(r);
    }


private:
    //==============================================================================

    // private member variables



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }
