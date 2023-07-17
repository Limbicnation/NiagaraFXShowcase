#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshActor.generated.h"

UCLASS()
class NIAGARAFXSHOWCASE_API AProceduralMeshActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AProceduralMeshActor();

    virtual void OnConstruction(const FTransform& Transform) override;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ProceduralMesh")
    int32 NumInstances = 10;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ProceduralMesh")
    float Offset = 100.0f;

    UPROPERTY(VisibleAnywhere)
    UInstancedStaticMeshComponent* InstancedStaticMeshComponent;

    virtual void BeginPlay() override;
};
