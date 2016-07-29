// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WallDecalInstruction.generated.h"

USTRUCT(BlueprintType)
struct LUMINEHALL_API FWallDecalInstruction : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	/** Id of the row */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Example)
	FName EntryId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	int32 x;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	int32 y;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	int32 size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	int32 indices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Example)
	TArray<int32> data;
};
