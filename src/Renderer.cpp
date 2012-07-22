#include "Renderer.h"
#include "GuiComponent.h"

std::vector<GuiComponent*> renderVector;

unsigned int Renderer::getScreenWidth() { return 1024; }
unsigned int Renderer::getScreenHeight() { return 768; }

void Renderer::registerComponent(GuiComponent* comp)
{
	renderVector.push_back(comp);
}

void Renderer::unregisterComponent(GuiComponent* comp)
{
	for(unsigned int i = 0; i < renderVector.size(); i++)
	{
		if(renderVector.at(i) == comp)
		{
			renderVector.erase(renderVector.begin() + i);
			break;
		}
	}
}

void Renderer::deleteAll()
{
	for(unsigned int i = 0; i < renderVector.size(); i++)
	{
		delete renderVector.at(i);
	}
	renderVector.clear();
}

void Renderer::render()
{
	for(unsigned int layer = 0; layer < LAYER_COUNT; layer++)
	{
		unsigned int layerBit = BIT(layer);
		for(unsigned int i = 0; i < renderVector.size(); i++)
		{
			if(renderVector.at(i)->getLayer() & layerBit)
				renderVector.at(i)->render();
		}
	}
}

