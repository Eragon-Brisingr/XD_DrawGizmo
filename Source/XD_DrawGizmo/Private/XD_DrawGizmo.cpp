// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "XD_DrawGizmo.h"
#include "XD_DrawGizmoEdMode.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "FXD_DrawGizmoModule"

void FXD_DrawGizmoModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FXD_DrawGizmoEdMode>(FXD_DrawGizmoEdMode::EM_XD_DrawGizmoEdModeId);
	GEngine->OnPostEngineInit.AddLambda([]()
		{
			GLevelEditorModeTools().AddDefaultMode(FXD_DrawGizmoEdMode::EM_XD_DrawGizmoEdModeId);
		});
}

void FXD_DrawGizmoModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FXD_DrawGizmoEdMode::EM_XD_DrawGizmoEdModeId);
	GEngine->OnPostEngineInit.RemoveAll(this);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXD_DrawGizmoModule, XD_DrawGizmo)