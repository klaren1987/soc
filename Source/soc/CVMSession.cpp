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

bool ACVMSession::processMSG(USocket* Connection, FString &messagecome)
{
	COMMMsg* pMsg;
	if (!IsValid(Connection))
	{
		UE_LOG(LogTemp, Warning, TEXT("IsValid(Connection)!"));
		return false;
	}
	
	// Set an FSocket pointer to the socket inside of the passed in USocket
	FSocket* MySocket = Connection->GetSocket();

	// Check if it is not a null pointer
	if (MySocket == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("MySocket == nullptr!"));
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
		
		
		pMsg=reinterpret_cast<COMMMsg*>(BinaryData.GetData());

		
	}


	///////
	messagecome=FString::FromInt(pMsg->msgtype);
	//UE_LOG(LogTemp, Warning, TEXT(c));
	
	switch (pMsg->msgtype) {
	case CPMsg082::TYPE: {
		FBPCPMsg82 temp;
		Message_82_Come(temp);
	}break;
	case CPMsg101::TYPE: {
		FBPCPMsg101 temp;
		CPMsg101 *m101 = reinterpret_cast<CPMsg101*>(BinaryData.GetData());
		temp.disaster = m101->disaster;
		temp.Fuel = m101->Fuel;
		temp.group = m101->group;
		temp.h = (int)(m101->h);
		UE_LOG(LogTemp, Warning, TEXT("msg: %d"), m101->msgtype);
		UE_LOG(LogTemp, Warning, TEXT("sizeof: %d"), sizeof(BinaryData.GetData()));
		UE_LOG(LogTemp, Warning, TEXT("Hight: %d"), m101->h);
		temp.Index = m101->Index;
		temp.infl = m101->infl;
		temp.master = m101->master;
		temp.mnvr = m101->mnvr;
		temp.nation = m101->nation;

		temp.numbering.Push(m101->numbering[0]);

		temp.numberingZRK = m101->numberingZRK;

		temp.numbering_out.Push(m101->numbering_out[0]);
		temp.numUnited = m101->numUnited;
		temp.objnum = m101->objnum;
		temp.real_course = m101->real_course;

		temp.rez.Push(m101->rez[0]);
		temp.signAbonentAction = m101->signAbonentAction;
		temp.signAbonentActionREB = m101->signAbonentActionREB;
		temp.signAbonentNotify = m101->signAbonentNotify;
		temp.signs = m101->signs;
		temp.tracking = m101->tracking;
		temp.type = m101->type;
		temp.vh = m101->vh;
		temp.vx = m101->vx;
		temp.vy = m101->vy;
		temp.x = m101->x;
		temp.y = m101->y;
		
		Message_101_Come(temp);
	}break;
	/*case CPMsg102::TYPE: {
		Message_102_Come();
	}
	*/
	case CPMsg103::TYPE: {
		FBPCPMsg103 temp;
		temp.srcObjnum = 1;
		Message_103_Come(temp);
	}break;
	case CPMsg107::TYPE: {
		FBPCPMsg107 temp;
		temp.pr_info = 1;
		Message_107_Come(temp);
	}break;
	case CPMsg108::TYPE: {
		FBPCPMsg108 temp;
		CPMsg108 *m108 = reinterpret_cast<CPMsg108*>(BinaryData.GetData());
		temp.NumAb = m108->numAb;
		temp.NumZRK = m108->numZRK;
		temp.code = m108->code;
		temp.m_numZU = m108->m_numZU;
		temp.numAirObjAb = m108->numAirObjAb;
		temp.numAirObjCP = m108->numAirObjCP;
		temp.numCannel = m108->numCannel;
		temp.pr_info = m108->pr_info;
		temp.QttRocket = m108->QttRocket;
		temp.RocketType = m108->RocketType;
		Message_108_Come(temp);
	}break;
/*	case CPMsg109::TYPE: {
		Message_109_Come();
	}
	*/
	case CPMsg112::TYPE: {
		FBPCPMsg112 temp;
		temp.x = 1;
		Message_112_Come(temp);
	}break;
/*	case CPMsg114::TYPE: {
		Message_114_Come();
	}
	*/
	case CPMsg117::TYPE: {
		FBPCPMsg117 temp;
		temp.x = 1;
		Message_117_Come(temp);
	}break;
	case CPMsg123::TYPE: {
		FBPCPMsg123 temp;
		temp.bearingObjects = 1;
		Message_123_Come(temp);
	}break;
	case CPMsg125::TYPE: {
		FBPCPMsg125 temp;
		temp.abNumber = 1;
		Message_125_Come(temp);
	}break;
	case CPMsg135::TYPE: {
		FBPCPMsg135 temp;
		temp.Azimut_RPH = 1;
		Message_135_Come(temp);
	}break;
	case CPMsg138::TYPE: {
		FBPCPMsg138 temp;
		temp.Channel = 1;
		Message_138_Come(temp);
	}break;
	case CPMsg139::TYPE: {
		FBPCPMsg139 temp;
		temp.numAbon = 1;
		Message_139_Come(temp);
	}break;
	case CPMsg148::TYPE: {
		FBPCPMsg148 temp;
		temp.Alert_CP = 1;
		Message_148_Come(temp);
	}break;
	case CPMsg157::TYPE: {
		FBPCPMsg157 temp;
		temp.data_type = 1;
		Message_157_Come(temp);
	}break;
	case CPMsg158::TYPE: {
		FBPCPMsg158 temp;
		temp.numAb = 1;
		Message_158_Come(temp);
	}break;
	default:
		break;
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