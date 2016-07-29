#include "LumineHall.h"
#include "Bitglyph.h"

bool FBitglyph::IsCharAssociated(const TCHAR& chr)
{
	int32 iterator = 0;
	while (iterator < assocChars.Len())
	{
		if (chr == assocChars[iterator])
		{
			return true;
		}
		iterator++;
	}
	return false;
}

int32 FBitglyph::Length()
{
	return width*height;
}