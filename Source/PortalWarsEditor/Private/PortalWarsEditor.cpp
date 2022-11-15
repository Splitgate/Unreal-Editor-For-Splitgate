#include "PortalWarsEditor.h"

DEFINE_LOG_CATEGORY(PortalWarsEditor);

#define LOCTEXT_NAMESPACE "FPortalWarsEditor"

void FPortalWarsEditor::StartupModule()
{
	UE_LOG(PortalWarsEditor, Warning, TEXT("PortalWarsEditor module has been loaded"));
}

void FPortalWarsEditor::ShutdownModule()
{
	UE_LOG(PortalWarsEditor, Warning, TEXT("PortalWarsEditor module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPortalWarsEditor, PortalWarsEditor)