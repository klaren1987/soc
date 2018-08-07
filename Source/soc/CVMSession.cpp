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


bool ACVMSession::SendCPMsg202(USocket* Connection)
{

	CPMsg202 _replyMsg202;
	_replyMsg202.msgsrcID = 0X55;
	_replyMsg202.msgdstID = 0x80;
	_replyMsg202.nomAbonnetwork = 5;
	// If the passed in socket is not valid
	if (!IsValid(Connection))
	{
		return false;
	}

	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		return false;
	}

	// Serialize the message
	TCHAR *serializedChar;// = Message.GetCharArray().GetData();
						  // Get / setup parameters
	int32 size = sizeof(_replyMsg202);
	serializedChar = (TCHAR*)malloc(size);
	memmove(serializedChar, &_replyMsg202, size);
	int32 sent = 0;

	// Send the message

	bool successful = MySocket->Send((uint8*)(serializedChar), size, sent);

	// And check if there was an error
	if (!successful)
	{
		UE_LOG(LogTemp, Error, TEXT("Error sending message!!"));
		return false;
	}
	else
	{
		return true;
	}

}