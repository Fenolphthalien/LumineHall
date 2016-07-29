#include "LumineHall.h"
#include "BitfontFunctionLibrary.h"
#include "Bitglyph.h"

#define SPACE_INDEX -1

void UBitfontFunctionLibrary::BuildBitstring(FBitfont& bitfont, TArray<bool>& bitBuffer, const FString& str)
{
	bitBuffer.Empty();

	int32 x = 0, y = bitfont.maxHeight, i = 0, length = str.Len(), glyphI = 0, row = 0;
	TArray<int32> indexes;

	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			x += bitfont.spaceValue;
			indexes.Add(SPACE_INDEX);
			continue;
		}
		else
		{
			for (glyphI = 0; glyphI < bitfont.glyphCount; glyphI++)
			{
				if (bitfont.bitglyphs[glyphI].IsCharAssociated(str[i]))
				{
					x += bitfont.bitglyphs[glyphI].width;
					indexes.Add(glyphI);
					x += bitfont.tracking;
					break;
				}
			}
		}
	}

	i = 0;
	int32 index = -2;
	bitBuffer.Init(false, x*y);

	while (i < indexes.Num())
	{
		if (indexes[i] > SPACE_INDEX)
		{
			index = indexes[i];
			bitfont.InsertCharacter(index, x, y, row, bitBuffer);

			row += bitfont.bitglyphs[i].width;
			row += bitfont.tracking;
		}
		else
		{
			row += bitfont.spaceValue;
		}
		i++;
	}
}

void UBitfontFunctionLibrary::BuildBitstringObject(FBitfont& bitfont, UAnimatedBitString*& bitString, const FString& str)
{
	TArray<bool> bitBuffer;

	if (bitString == nullptr)
	{
		bitString = NewObject<UAnimatedBitString>();
	}
	int32 x = 0, y = bitfont.maxHeight, i = 0, length = str.Len(), glyphI = 0, row = 0;
	TArray<int32> indexes;

	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			x += bitfont.spaceValue;
			indexes.Add(SPACE_INDEX);
			continue;
		}
		else
		{
			for (glyphI = 0; glyphI < bitfont.glyphCount; glyphI++)
			{
				if (bitfont.bitglyphs[glyphI].IsCharAssociated(str[i]))
				{
					indexes.Add(glyphI);
					x += bitfont.bitglyphs[glyphI].width;
					x += bitfont.tracking;
					break;
				}
			}
		}
	}

	i = 0;
	int32 index = 0;
	bitBuffer.Init(false, x*y);

	while (i < indexes.Num())
	{
		if (indexes[i] > SPACE_INDEX && indexes[i] < bitfont.glyphCount)
		{
			index = indexes[i];
			bitfont.InsertCharacter(index,x,y,row,bitBuffer);

			row += bitfont.bitglyphs[index].width;
			row += bitfont.tracking;
		}
		else if (indexes[i] == SPACE_INDEX)
		{
			row += bitfont.spaceValue;
		}
		i++;
	}

	bitString->Stop();
	bitString->width = x;
	bitString->height = y;
	bitString->bitString = bitBuffer;
}

void UBitfontFunctionLibrary::BuildBitstringObjects(FBitfont& bitfont, UAnimatedBitString*& bitString, const FString& str, UBitcanvas*& bitCanvas, TArray<UDecalComponent*> _decals, int32 _width, int32 _height)
{
	BuildBitstringObject(bitfont, bitString, str);
	if (bitCanvas == nullptr)
	{
		bitCanvas = NewObject<UBitcanvas>();
	}
	bitCanvas->SafeSet(_decals, _width, _height);
}

bool UBitfontFunctionLibrary::IsBitstringSafeToTick(UAnimatedBitString* bitString)
{
	if (bitString == nullptr)
		return false;
	return bitString->IsEnabled();
}

bool UBitfontFunctionLibrary::IsBitAnimationSafeToTick(UAnimatedBitString* bitString, UBitcanvas* bitCanvas)
{
	if (bitString == nullptr || bitCanvas == nullptr)
		return false;
	return bitString->IsEnabled();
}

//void UBitfontFunctionLibrary::SafeSet(FBitcanvas& bitcanvas, TArray<UDecalComponent*> _decals, int32 _width, int32 _height)
//{
//	bitcanvas.SafeSet(_decals,_width,_height);
//}
//
//void UBitfontFunctionLibrary::PushRightToLeft(FBitcanvas& bitcanvas,const TArray<bool>& inArray)
//{
//	bitcanvas.PushRightToLeft(inArray);
//}