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

bool ACVMSession::processMSG(USocket* Connection);
{
	COMMMsg* pMsg;
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


	// Credit to RAMA for this converter!
	//Binary Array!
	TArray<uint8> BinaryData;
	uint32 Size;

	while (MySocket->HasPendingData(Size))
	{
		// Be sure that the array doesn't become absolutely insanely large
		BinaryData.Init(0, FMath::Min(Size, 65507u));

		// Set the counter for the ammount of bytes read to 0
		int32 Read = 0;
		// Recieve the data from the socket and put it into the binary array
		MySocket->Recv(BinaryData.GetData(), BinaryData.Num(), Read);
	}

	// Check if there was actually data read into the array
	if (BinaryData.Num() <= 0)
	{
		// No data was read!
		UE_LOG(LogTemp, Warning, TEXT("No data to read!"));
		return false;
	}
	else
	{
		// Be sure to \0 terminate the array
		
		// Convert it to an fstring and set the passed in message parameter
		pMsg=reinterpret_cast<COMMMsg*>(BinaryData.GetData()));

		
	}


	///////
	

	
	switch (pMsg->msgtype) {
	case CPMsg82::TYPE: {

	}break;
	case CPMsg112::TYPE: {

	}break;
	case CPMsg123::TYPE: {

	}break;
	default: {

	}break;
	}
	return true;
}


bool ACVMSession::SendCPMsg202(USocket* Connection)
{

	CPMsg202 _replyMsg202;
	_replyMsg202.msgsrcID = 0X51;
	_replyMsg202.msgdstID = 0x80;
	_replyMsg202.nomAbonnetwork = 0x51;
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