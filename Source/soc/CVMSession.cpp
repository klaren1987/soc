// Fill out your copyright notice in the Description page of Project Settings.

#include "CVMSession.h"


// Sets default values
ACVMSession::ACVMSession()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACVMSession::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACVMSession::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACVMSession::test()
{
	Message_1_Come();
}