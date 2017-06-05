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
{
public:

	//ScopedPointer<Component> currentDemo;
	bool keyPressed(const KeyPress& key) override
	{
		//[UserCode_keyPressed] -- Add your code here...

		DBG("MainContentComponent keyPressed");
		return false;
	}
	Component * c;
    //==============================================================================
    MainContentComponent()
    {
		//setOpaque(true);
	
      setSize (500, 600);
	  TStringLst * s = TStringLst::getDemoTypeList()["ThreeDTest"];
	  
	  if (s)
	  {
		  addAndMakeVisible( s->createComponent());
	  }


	  s = TStringLst::getDemoTypeList()["ThreeDTest2"];

	  if (s)
	  {
		 c = s->createComponent();
		
		  addAndMakeVisible(c);
		
	  }



	  s = TStringLst::getDemoTypeList()["Editor"];
	  if (s)
	  {
		  Component * editor = s->createComponent();
		  addAndMakeVisible(editor);
		  editor->setName("Editor");
		  //String en = editor->getName();
		 // DBG(en);
	  }


	  //c->setFocusContainer(true);
	 // this->focusGained(FocusChangeType::focusChangedByMouseClick);
	  resized();
    }

    ~MainContentComponent()
    {
		//currentDemo = nullptr;
    }

 

    void paint (Graphics& g) override
    {
	//	
        // You can add your component specific drawing code here!
        // This will draw over the top of the openGL background.
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
		//auto r = getLocalBounds();
		//if (currentDemo != nullptr)
		//	currentDemo->setBounds(r);

	
		FlexBox masterbox;
		masterbox.flexDirection = FlexBox::Direction::column;// column;// : FlexBox::Direction::row;
		masterbox.alignItems = FlexBox::AlignItems::stretch;
		masterbox.alignContent = FlexBox::AlignContent::stretch;
		masterbox.flexWrap = FlexBox::Wrap::wrap;
		masterbox.justifyContent = FlexBox::JustifyContent::center;
		


		int num = getNumChildComponents();
		for (auto i = 0; i < num; i++)
		{
			auto c = getChildComponent(i);
			if (c)
			{
				masterbox.items.add(FlexItem(1, 1).withFlex(1).withMargin(10));
				auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
				flexitem.associatedComponent = c;
			}
		}
		Rectangle<float> r = getLocalBounds().toFloat();
		r.reduce(10.0f, 10.0f);
		masterbox.performLayout(r);
    }


private:
    //==============================================================================

    // private member variables



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }
