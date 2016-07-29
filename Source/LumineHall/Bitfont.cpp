#include "LumineHall.h"
#include "Bitfont.h"
#include "Bitglyph.h"

void FBitfont::AddSpace(const int32& height, TArray<bool>& buffer, const bool& clear)
{
	if (clear)
		buffer.Empty();

	int32 add = height * spaceValue, it = 0;
	while (it < add)
	{
		buffer.Add(false);
		it++;
	}
}

void FBitfont::AddTracking(const int32& height, TArray<bool>& buffer, const bool& clear)
{
	if (clear)
		buffer.Empty();

	int32 add = height * tracking, it = 0;
	while (it < add)
	{
		buffer.Add(false);
		it++;
	}
}

void FBitfont::InsertCharacter(const int32& character, const int32& arrayWidth, const int32& height, const int32& atRow, TArray<bool>& buffer)
{
	int32 index,
		glyphIndex,
		characterWidth = bitglyphs[character].width,
		minHeight = (height <= bitglyphs[character].height) ?
		height : bitglyphs[character].height;

	TArray<bool> characterBits = bitglyphs[character].bitArray;

	for (int32 y = 0; y < height; y++)
	{
		for (int32 x = 0; x < characterWidth; x++)
		{
			index = (y * arrayWidth + x) + atRow;
			glyphIndex = y*characterWidth + x;
			buffer[index] = characterBits[glyphIndex];
		}
	}
}