// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataTableActor.generated.h"

UCLASS()
class LUMINEHALL_API ADataTableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	ADataTableActor();
	
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UDataTable* dataTable;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
};
