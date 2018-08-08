// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketerBPLibrary.h"
#include "CPMsg.h"
#include "COMMMsg.h"
#include "CPGFMsg.h"
#include "CVMSession.generated.h"



USTRUCT(BlueprintType)
struct  FBPCPMsg108
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int Cfolor;
	    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int Scale3D;		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int NumAb;		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int NumZRK;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numAirObjCP;		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numAirObjAb;	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int pr_info;		
		enum
		{
			REPORT_AIR_OBJ_TO = 0x02,
			
			REPORT_AIR_OBJ_FROM = 0x08,
			
			REPORT_INDEPENDENT = 0x10
		};		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int code;	
		enum
		{
			
			ON_CANCEL_LAST_COMMAND1 = 0x00,
			
			TELEPHONE = 0x01,
			
			ON_DESTROY_AIR_OBJ = 0x11,
			 
			END_BO = 0x20,
			
			ON_PROHIBIT_INFLUENCE = 0x22,
			//command: "absolute prohibition of influence on air object " was received.
			ON_ABS_PROHIBIT_INFLUENCE = 0x22,
			//command: "prohibition of launch rocket" was received 
			ON_PROHIBIT_LAUNCH_ROCKET = 0x24,
			//command: "permit of launch rocket" was received  
			ON_PERMIT_LAUNCH_ROCKET = 0x33,
			//rocket was launched 
			ROCKET_LAUNCHED = 0x41,
			//air object skipped 
			AIR_OBJ_SKIP = 0x43,
			//air object destroyed 
			AIR_OBJ_DESTROYED = 0x45,
			//air object captured
			AIR_OBJ_CAPTURED = 0x46,
			//air object was designated on target channel
			AIR_OBJ_DESIGNATED_ON_TC = 0x47,
			//air object taken on tracking 
			AIR_OBJ_ON_TRACKING = 0x48,
			//air object search
			AIR_OBJ_SEARCHING = 0x49,
			//air object in zone
			AIR_OBJ_IN_ZONE = 0x50,
			//command:"detect air object by bearing" was received 
			ON_DETECT_AIR_OBJ_BY_BEARING = 0x51,
			//mitting (flying)
			MITTING = 0x52,
			//reject target designation
			RJCT_TD_AIR_OBJ = 0x55,
			//command: "cancelation target designation" was completed
			CANCEL_TD_RCVD = 0x92,
			//command: "prohibition of launch rocket" was completed 
			ON_PROHIBIT_LAUNCH_ROCKET_COMPL = 0x94,
			//command: "cancelation last command" was received
			ON_CANCEL_LAST_COMMAND2 = 0x99
		};
		/*! \var COUInt8 Channel;
		\brief Number of the channel.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numCannel;

		/*! \var COUInt8 RocketType;
		\brief type of the rocket.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int RocketType;

		/*! \var COUInt8 QttRocket;
		\brief Quantity of spent rockets.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int QttRocket;

		/*! \var COUInt8 m_numZU;
		\brief number ZU.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int m_numZU;

};

UCLASS()
class SOC_API ACVMSession : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACVMSession();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send CPMsg202", Keywords = "CPMsg202"), Category = "TCP Messages for CVM")
		static bool SendCPMsg202(USocket* Connection);
	UFUNCTION(BlueprintCallable, Category = "TCP Messages for CVM")
		bool processMSG(USocket* Connection, FString &messagecome);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_82_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_108_Come(FBPCPMsg108 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_112_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_123_Come();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

