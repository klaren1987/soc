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
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send CPMsg202", Keywords = "CPMsg202"), Category = "TCP Messages for CVM")
		static bool SendCPMsg202(USocket* Connection);
	UFUNCTION(BlueprintCallable, Category = "TCP Messages for CVM")
		void test();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_2_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_3_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_4_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_5_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_6_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_7_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_8_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_9_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_10_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_11_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_12_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_13_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_14_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_15_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_16_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_17_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_18_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_19_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_20_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_21_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_22_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_23_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_24_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_25_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_26_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_27_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_28_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_29_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_30_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_31_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_32_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_33_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_34_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_35_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_36_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_37_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_38_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_39_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_40_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_41_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_42_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_43_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_44_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_45_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_46_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_47_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_48_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_49_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_50_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_51_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_52_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_53_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_54_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_55_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_56_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_57_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_58_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_59_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_60_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_61_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_62_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_63_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_64_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_65_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_66_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_67_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_68_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_69_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_70_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_71_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_72_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_73_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_74_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_75_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_76_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_77_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_78_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_79_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_80_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_81_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_82_Come();
/*	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();

		*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
