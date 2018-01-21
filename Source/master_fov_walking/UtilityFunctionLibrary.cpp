// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityFunctionLibrary.h"
#include "Paths.h"
#include "PlatformFilemanager.h"
#include "FileHelper.h"

FVector UUtilityFunctionLibrary::FlattenPos3D(FVector vec, float height)
{
    return FVector(vec.X, vec.Y, height);
}

float UUtilityFunctionLibrary::GetSignedAngle(FVector prevDir, FVector currDir)
{
    return FMath::Sign(FVector::CrossProduct(prevDir, currDir).Z) * FMath::RadiansToDegrees(acosf(FVector::DotProduct(prevDir, currDir)));
}

bool UUtilityFunctionLibrary::DoesFileExist(FString filename)
{
    return FPaths::FileExists(filename);
}

bool UUtilityFunctionLibrary::FileIO__SaveStringTextToFile(
    FString SaveDirectory,
    FString JoyfulFileName,
    FString SaveText,
    bool AllowOverWriting
) {
    if (!FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*SaveDirectory))
    {
        //Could not make the specified directory
        return false;
        //~~~~~~~~~~~~~~~~~~~~~~
    }

    //get complete file path
    SaveDirectory += "\\";
    SaveDirectory += JoyfulFileName;

    //No over-writing?
    if (!AllowOverWriting)
    {
        //Check if file exists already
        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
        {
            //no overwriting
            return false;
        }
    }

    return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}

bool UUtilityFunctionLibrary::FileIO__LoadStringFromFile(FString FileNameA, FString& SaveTextA)
{
    return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}