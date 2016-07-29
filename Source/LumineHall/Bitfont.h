#pragma once

#include "Bitglyph.h"
#include "Bitfont.generated.h"

USTRUCT(BlueprintType)
struct LUMINEHALL_API FBitfont : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	/*
	public byte tracking = 1, spaceValue = 5;
	public int glyphCount, maxHeight;
	public Bitglyph_t[] bitglyphs;
	*/

	/** Id of the row */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	FName EntryId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Example)
	int32 tracking;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Example)
	int32 spaceValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Example)
	int32 glyphCount;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Example)
	int32 maxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	TArray<FBitglyph> bitglyphs;

	void AddSpace(const int32& height, TArray<bool>& buffer, const bool& clear);

	void AddTracking(const int32& height, TArray<bool>& buffer, const bool& clear);

	void InsertCharacter(const int32& character, const int32& arrayWidth, const int32& height, const int32& atRow, TArray<bool>& buffer);
};