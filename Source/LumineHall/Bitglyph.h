#pragma once

#include "Bitglyph.generated.h"

USTRUCT(BlueprintType)
struct LUMINEHALL_API FBitglyph
{
	GENERATED_USTRUCT_BODY()

public:


	/*public int width, height;
	public string assocChars;

	public bool[] bitArray; */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	int32 width;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	int32 height;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	FString assocChars;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	TArray<bool> bitArray;

	bool IsCharAssociated(const TCHAR& chr);
	
	int32 Length();
};