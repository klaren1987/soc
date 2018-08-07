// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketerBPLibrary.h"
#include "CVMSession.generated.h"


UCLASS()
class SOC_API ACVMSession : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACVMSession();
	UFUNCTION(BlueprintCallable, Category = "TCP Messages")
		void test();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages")
		void Message_1_Come();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
