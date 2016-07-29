#pragma once

#include "Object.h"
#include "AnimatedBitString.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBitstringAnimationCallback);

UCLASS(BlueprintType)
class LUMINEHALL_API UAnimatedBitString : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	int32 width;

	UPROPERTY()
	int32 height;

	UPROPERTY(VisibleAnywhere)
	TArray<bool> bitString;

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	bool Tick(const float& delta,TArray<bool>& outBuffer);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void Start(const int32& _waitFramesBeforeStop, const float& _newFrameEvery);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void StartAfter(const int32& _waitFramesBeforeStop, const float& _newFrameEvery, const float& delaySeconds);

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void Stop();

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	void Pause();

	UFUNCTION(BlueprintCallable, Category = "Bitfont Functions")
	bool IsEnabled();

	UFUNCTION(BlueprintPure, Category = "Bitfont Functions")
	int32 TotalFrames();

	UFUNCTION(BlueprintPure, Category = "Bitfont Functions")
	float AnimationLength();

	UFUNCTION(BlueprintPure, Category = "Bitfont Functions")
	float AnimationElapsed(bool clamp);

	UFUNCTION(BlueprintPure, Category = "Bitfont Functions")
	float AnimationElapsedUnscaled();

	UPROPERTY(BlueprintAssignable, Category = "Callbacks")
	FBitstringAnimationCallback OnAnimationStart;

	UPROPERTY(BlueprintAssignable, Category = "Callbacks")
	FBitstringAnimationCallback OnAnimationStop;

	UPROPERTY(BlueprintAssignable, Category = "Callbacks")
	FBitstringAnimationCallback OnAnimationPause;

private:
	
	UPROPERTY(VisibleAnywhere)
	int32 waitFramesBeforeStop;

	UPROPERTY(VisibleAnywhere)
	float newFrameEvery;

	UPROPERTY(VisibleAnywhere)
	float time;

	UPROPERTY(VisibleAnywhere)
	float totalTime;

	UPROPERTY(VisibleAnywhere)
	float delay;

	UPROPERTY(VisibleAnywhere)
	float animDivider;

	UPROPERTY(VisibleAnywhere)
	int32 columnPointer;

	UPROPERTY(VisibleAnywhere)
	bool bEnabled;

	int32 LockMemoryLength();
};