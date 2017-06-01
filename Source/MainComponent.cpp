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

	ScopedPointer<Component> currentDemo;

	
    //==============================================================================
    MainContentComponent()
    {
		//setOpaque(true);
	
      setSize (500, 600);
	  TStringLst * s = TStringLst::getDemoTypeList()["ThreeDTest"];
	  if (s)
	  {
		  addAndMakeVisible(currentDemo = s->createComponent());
	  }
		
		//addAndMakeVisible(nc);


		//addAndMakeVisible(nc1);
		//TStringLst::getDemoTypeList().
  
    }

    ~MainContentComponent()
    {
		currentDemo = nullptr;
    }

 

    void paint (Graphics& g) override
    {

        // You can add your component specific drawing code here!
        // This will draw over the top of the openGL background.
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
		auto r = getLocalBounds();
		if (currentDemo != nullptr)
			currentDemo->setBounds(r);
    }


private:
    //==============================================================================

    // private member variables



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }
