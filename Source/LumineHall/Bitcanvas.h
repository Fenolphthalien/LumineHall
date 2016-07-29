#pragma once

#include "Object.h"
#include "Bitcanvas.generated.h"

UCLASS(BlueprintType)
class LUMINEHALL_API UBitcanvas : public UObject
{	
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void SafeSet(const TArray<UDecalComponent*>& _decals,const int32& _width, const int32& _height);
	
	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void PushRightToLeft(const TArray<bool>& inArray);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void AssignMaterial(UMaterial* material);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void SetDisplayAll(bool display);

	UFUNCTION(BlueprintPure, Category = "Bitfont Functions")
	void GetCanvasCenter(float& x, float& y);

private:
	UPROPERTY()
	int32 width;

	UPROPERTY()
	int32 height;

	UPROPERTY()
	TArray<UDecalComponent*> decals;
};