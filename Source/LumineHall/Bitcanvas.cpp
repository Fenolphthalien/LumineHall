#include "LumineHall.h"
#include "Bitcanvas.h"

void UBitcanvas::SafeSet(const TArray<UDecalComponent*>& _decals, const int32& _width,const int32& _height)
{
	int32 decalsCount = _decals.Num(), decalsLength = _width*+_height;
	if (decalsCount != decalsLength)
		return;
	width = _width;
	height = _height;
	decals = _decals;
}

void UBitcanvas::PushRightToLeft(const TArray<bool>& inArray)
{
	TArray < UDecalComponent*> blankBuffer;
	int32 index, i = 0;

	//Push the last column of decals into the blank buffer.
	for (i = 0; i < height; i++)
	{
		index = i * width + (width - 1);
		blankBuffer.Add(decals[index]);
	}

	int32 iy = 0, ix = 0;

	for (iy = 0; iy < height; iy++)
	{
		for (ix = 1; ix < width; ix++)
		{
			index = iy*width + ix;
			decals[index - 1]->SetVisibility(decals[index]->IsVisible());
		}
	}

	//Fill last column with InArray.
	i = 0;
	int32 yMin = height > inArray.Num() ? 
		inArray.Num() : height;

	while (i < yMin)
	{
		blankBuffer[i]->SetVisibility(inArray[i]);
		i++;
	}
}

void UBitcanvas::AssignMaterial(UMaterial* material)
{
	int32 iterator = 0;
	while (iterator < decals.Num())
	{
		decals[iterator]->SetDecalMaterial(material);
		iterator++;
	}
}

void UBitcanvas::SetDisplayAll(bool display)
{
	int32 iterator = 0;
	while (iterator < decals.Num())
	{
		decals[iterator]->SetVisibility(display);
		iterator++;
	}
}

void UBitcanvas::GetCanvasCenter(float& x, float& y)
{
	x = width * 0.5f;
	y = height * 0.5f;
}
