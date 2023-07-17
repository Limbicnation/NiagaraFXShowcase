#include "ProceduralMeshActor.h"
#include "Components/InstancedStaticMeshComponent.h"

AProceduralMeshActor::AProceduralMeshActor()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
    SetRootComponent(InstancedStaticMeshComponent);
    InstancedStaticMeshComponent->SetMobility(EComponentMobility::Static);
    InstancedStaticMeshComponent->SetGenerateOverlapEvents(false);
}

void AProceduralMeshActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    if (InstancedStaticMeshComponent->GetInstanceCount() == 0)
    {
        TArray<FTransform> Transforms;
        Transforms.Empty(NumInstances);

        for (int Index = 0; Index < NumInstances; ++Index)
        {
            Transforms.Add(FTransform(FVector(0.0f, Offset * Index, 0.0f)));
        }

        InstancedStaticMeshComponent->AddInstances(Transforms, false);
    }
}

void AProceduralMeshActor::BeginPlay()
{
    Super::BeginPlay();
}

void AProceduralMeshActor::Tick(float DeltaSeconds)
{
    // ... (unchanged part of the Tick method)
}
