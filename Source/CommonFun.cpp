#include "CommonFun.h"

Component* getChildComponentByName(Component* parent, String name)
{
	if (parent)
	{
		int n = parent->getNumChildComponents();
		for (int i = 0; i < n; i++)
		{
			Component * c = parent->getChildComponent(i);

			if (c)
			{
				String s = c->getName();
				if (s == name)
				{
					return c;
				}
			}
		}
	}

	return nullptr;
}

ShaderData g_shaderData;