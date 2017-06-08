/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ShaderEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#include "ComponentList.h"

extern ShaderData g_shaderData;
//[/MiscUserDefs]

//==============================================================================
ShaderEditor::ShaderEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (ThreedScene = new ThreeDTest());
    addAndMakeVisible (editor = new Editor());
    addAndMakeVisible (comboBox = new ComboBox ("combobox"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	//Array<ShaderPreset> presets(g_shaderData.presets);


	for (int i = 0; i < g_shaderData._shaderPreset.size(); ++i)
		comboBox->addItem(g_shaderData._shaderPreset[i]->name, i + 1);


	comboBox->setSelectedItemIndex(0);





/*
	Component *editor = getChildComponentByName(this, "Editor");

	Component *tabShader = getChildComponentByName(editor, "tabShader");

	if (tabShader)
	{
		TabbedComponent* tc = (TabbedComponent*)tabShader;
		int n = tc->getNumChildComponents();

		if (n != 2)
			return;

		juce::CodeEditorComponent * vertexEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(0);
		juce::CodeEditorComponent * fragmentEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(1);
		if (vertexEditorComp)
		{
			if (vertexEditorComp->getDocument().getNumCharacters() < 3)
				vertexEditorComp->getDocument().replaceAllContent(getPresets()[comboBox->getSelectedItemIndex()].vertexShader);

			if (fragmentEditorComp->getDocument().getNumCharacters() < 3)
				fragmentEditorComp->getDocument().replaceAllContent(getPresets()[comboBox->getSelectedItemIndex()].fragmentShader);
		}
	}
*/


	resized();
    //[/Constructor]
}

ShaderEditor::~ShaderEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ThreedScene = nullptr;
    editor = nullptr;
    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	//td = nullptr;
	//e = nullptr;
    //[/Destructor]
}

//==============================================================================
void ShaderEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ShaderEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    ThreedScene->setBounds (48, 32, 300, 200);
    editor->setBounds (64, 400, 300, 200);
    comboBox->setBounds (48, 320, 150, 24);
    //[UserResized] Add your own custom resize handling here..

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
		if (c)
		{
			String n = c->getName();
		//	DBG(n);
			if (n == "combobox")
			{
				if (masterbox.items.size() >= 2)
				{
					masterbox.items.insert(1, FlexItem(1, 1).withFlex(1).withMargin(10));
					auto& flexitem = masterbox.items.getReference(1);
					flexitem.associatedComponent = c;
				}
				else
				{
					masterbox.items.add(FlexItem(1, 1).withFlex(1).withMargin(10));
					auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
					flexitem.associatedComponent = c;
				}

			}
			else
			{

				masterbox.items.add(FlexItem(1, 1).withFlex(8).withMargin(10));
				auto& flexitem = masterbox.items.getReference(masterbox.items.size() - 1);
				flexitem.associatedComponent = c;
			}


		}
	}
	Rectangle<float> r = getLocalBounds().toFloat();
	//r.reduce(10.0f, 10.0f);
	masterbox.performLayout(r);

    //[/UserResized]
}

void ShaderEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
		//String s;
		//DBG(comboBox->getSelectedItemIndex() << " index is select");
		
		Component *editor = getChildComponentByName(this, "Editor");

		Component *tabShader = getChildComponentByName(editor, "tabShader");

		if (tabShader)
		{
			TabbedComponent* tc = (TabbedComponent*)tabShader;
			int n = tc->getNumChildComponents();

			if (n != 2)
				return;

			juce::CodeEditorComponent * vertexEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(0);
			juce::CodeEditorComponent * fragmentEditorComp = (juce::CodeEditorComponent *)tc->getTabContentComponent(1);
			if (vertexEditorComp)
			{
				if (  comboBox->getSelectedItemIndex() == 0)
				{
					if (!vertexEditorComp->getDocument().getLine(0).contains("/1"))
					{
						vertexEditorComp->getDocument().replaceAllContent(g_shaderData._shaderPreset[comboBox->getSelectedItemIndex()]->vertexShader);
					}
					if (!fragmentEditorComp->getDocument().getLine(0).contains("/1"))
					{
						fragmentEditorComp->getDocument().replaceAllContent(g_shaderData._shaderPreset[comboBox->getSelectedItemIndex()]->fragmentShader);
					}
				}
				
				if (comboBox->getSelectedItemIndex() == 1)
				{
					String s = vertexEditorComp->getDocument().getLine(0);
					if (!s.contains("/2"))
					{
						vertexEditorComp->getDocument().replaceAllContent(g_shaderData._shaderPreset[comboBox->getSelectedItemIndex()]->vertexShader);
					}
					if (!fragmentEditorComp->getDocument().getLine(0).contains("/2"))
					{
						fragmentEditorComp->getDocument().replaceAllContent(g_shaderData._shaderPreset[comboBox->getSelectedItemIndex()]->fragmentShader);
					}
				}
			}
		}
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
static ComponentList<ShaderEditor> td((const String)("ShaderEditor"));

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ShaderEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="10aea56741338efc" memberName="ThreedScene" virtualName=""
             explicitFocusOrder="0" pos="48 32 300 200" sourceFile="ThreeDTest.cpp"
             constructorParams=""/>
  <JUCERCOMP name="Editora" id="9c071996b5695aaa" memberName="editor" virtualName=""
             explicitFocusOrder="0" pos="64 400 300 200" sourceFile="Editor.cpp"
             constructorParams=""/>
  <COMBOBOX name="combobox" id="2a3d114fe30305ba" memberName="comboBox" virtualName=""
            explicitFocusOrder="0" pos="48 320 150 24" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
