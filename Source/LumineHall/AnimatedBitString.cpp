#include "LumineHall.h"
#include "AnimatedBitString.h"

bool UAnimatedBitString::Tick(const float& delta, TArray<bool>& outBuffer)
{
	if (!bEnabled)
		return false;

	//Handle delay - return if delay is greater than 0 and therefore active.
	if (delay > 0)
	{
		delay -= delta;
		return false;
	}

	time += delta;
	totalTime += delta;

	if (time < newFrameEvery)
		return false;

	outBuffer.Empty();
	if (columnPointer < width)
	{
		for (int i = 0; i < height; i++)
		{
			outBuffer.Add(bitString[width * i + columnPointer]);
		}
	}
	else
	{	
		for (int i = 0; i < height; i++)
		{
			outBuffer.Add(false);
		}
	}
	columnPointer++;
	time -= newFrameEvery;
	if (width + waitFramesBeforeStop <= columnPointer)
	{
		Stop();
	}
	return true;
}

void UAnimatedBitString::Start(const int32& _waitFramesBeforeStop, const float& _newFrameEvery)
{
	bEnabled = true;
	newFrameEvery = _newFrameEvery;
	waitFramesBeforeStop = _waitFramesBeforeStop;
	if (OnAnimationStart.IsBound())
		OnAnimationStart.Broadcast();
	animDivider = 1.0f / AnimationLength();
}

void UAnimatedBitString::StartAfter(const int32& _waitFramesBeforeStop, const float& _newFrameEvery, const float& delaySeconds)
{
	delay = delaySeconds;
	Start(_waitFramesBeforeStop, _newFrameEvery);
	animDivider = 1.0f / (AnimationLength() + delay);
}

void UAnimatedBitString::Stop()
{
	bEnabled = false;
	columnPointer = 0;
	time = 0;
	totalTime = 0;
	if (OnAnimationStop.IsBound())
		OnAnimationStop.Broadcast();
}

void UAnimatedBitString::Pause()
{
	bEnabled = false;
	if (OnAnimationPause.IsBound())
		OnAnimationPause.Broadcast();
}

bool UAnimatedBitString::IsEnabled()
{
	return bEnabled;
}

int32 UAnimatedBitString::LockMemoryLength()
{
	int32 length = 0;
	length += sizeof(width);
	length += sizeof(height);
	length += sizeof(bitString);
	length += sizeof(waitFramesBeforeStop);
	length += sizeof(newFrameEvery);
	return length;
}

int32 UAnimatedBitString::TotalFrames()
{ 
	return width + waitFramesBeforeStop;
}

float UAnimatedBitString::AnimationLength()
{
	return TotalFrames() * newFrameEvery;
}

float UAnimatedBitString::AnimationElapsed(bool clamp)
{
	float f = totalTime * animDivider;
	if (clamp)
	{
		f = (f > 0 ? f : 0) <= 1 ? f : 1;
	}
	return f;
}

float UAnimatedBitString::AnimationElapsedUnscaled()
{
	return totalTime;
}