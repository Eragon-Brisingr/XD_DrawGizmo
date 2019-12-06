// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "XD_DrawGizmoEdMode.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "XD_DrawGizmoInterface.h"
#include "EditorModes.h"

const FEditorModeID FXD_DrawGizmoEdMode::EM_XD_DrawGizmoEdModeId = TEXT("EM_XD_DrawGizmoEdMode");

FXD_DrawGizmoEdMode::FXD_DrawGizmoEdMode()
{

}

FXD_DrawGizmoEdMode::~FXD_DrawGizmoEdMode()
{

}

void FXD_DrawGizmoEdMode::Enter()
{
	FEdMode::Enter();
}

void FXD_DrawGizmoEdMode::Exit()
{
	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FXD_DrawGizmoEdMode::UsesToolkits() const
{
	return false;
}

bool FXD_DrawGizmoEdMode::IsCompatibleWith(FEditorModeID OtherModeID) const
{
	return OtherModeID != FBuiltinEditorModes::EM_None;
}

void FXD_DrawGizmoEdMode::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
	UWorld* World = GetWorld();
	for (TActorIterator<AActor> It(World); It; ++It)
	{
		AActor* Actor = *It;
		if (IXD_DrawGizmoInterface* DrawGizmo = Cast<IXD_DrawGizmoInterface>(Actor))
		{
			DrawGizmo->DrawGizmoNative(View, Viewport, PDI, Actor->IsSelectedInEditor());
		}
	}
}

void FXD_DrawGizmoEdMode::DrawHUD(FEditorViewportClient* ViewportClient, FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	UWorld* World = GetWorld();
	for (TActorIterator<AActor> It(World); It; ++It)
	{
		AActor* Actor = *It;
		if (IXD_DrawGizmoInterface* DrawGizmo = Cast<IXD_DrawGizmoInterface>(Actor))
		{
			DrawGizmo->DrawHUDNative(Viewport, View, Canvas, Actor->IsSelectedInEditor());
		}
	}
}


