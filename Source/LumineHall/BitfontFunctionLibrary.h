#pragma once

#include "Bitfont.h"
#include "AnimatedBitString.h"
#include "Bitcanvas.h"
#include "BitfontFunctionLibrary.generated.h"

UCLASS()
class UBitfontFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	static void BuildBitstring(UPARAM(ref)FBitfont& bitfont, UPARAM(ref)TArray<bool>& bitBuffer, UPARAM(ref)const FString& str);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	static void BuildBitstringObject(UPARAM(ref)FBitfont& bitfont, UPARAM(ref)UAnimatedBitString*& bitString, UPARAM(ref)const FString& str);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	static void BuildBitstringObjects(UPARAM(ref)FBitfont& bitfont, UPARAM(ref)UAnimatedBitString*& bitString, UPARAM(ref)const FString& str, UPARAM(ref)UBitcanvas*& bitCanvas, TArray<UDecalComponent*> _decals, int32 _width, int32 _height);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	static bool IsBitstringSafeToTick(UAnimatedBitString* bitString);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	static bool IsBitAnimationSafeToTick(UAnimatedBitString* bitString, UBitcanvas* bitCanvas);
};