// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MASTER_FOV_WALKING_API UUtilityFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Utlility")
    static FVector FlattenPos3D(FVector vec, float height = 0);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Utlility")
    static float GetSignedAngle(FVector prevDir, FVector currDir);

    /** Saves text to filename of your choosing, make sure include whichever file extension you want in the filename,
    ex: SelfNotes.txt . Make sure to include the entire file path in the save directory, ex: C:\MyGameDir\BPSavedTextFiles */
    UFUNCTION(BlueprintCallable, Category = "Victory BP Library|File IO")
    static bool FileIO__SaveStringTextToFile(FString SaveDirectory, FString JoyfulFileName, FString SaveText, bool AllowOverWriting = false);

    UFUNCTION(BlueprintCallable, Category = "Victory BP Library|File IO")
    static bool FileIO__LoadStringFromFile(FString FileNameA, FString& SaveTextA);
	
};
