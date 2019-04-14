// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "XD_DrawGizmoInterface.generated.h"

class FSceneView;
class FViewport;
class FPrimitiveDrawInterface;
class FCanvas;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UXD_DrawGizmoInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class XD_DRAWGIZMORUNTIME_API IXD_DrawGizmoInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void DrawGizmoNative(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI, bool IsSelected) {}
	virtual void DrawHUDNative(FViewport* Viewport, const FSceneView* View, FCanvas* Canvas, bool IsSelected) {}
};
