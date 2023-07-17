#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshActor.generated.h"

UCLASS()
class NIAGARAFXSHOWCASE_API AProceduralMeshActor final : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralMeshActor();

	virtual void OnConstruction(const FTransform& Transform) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "ProceduralMesh")
	int32 NumInstances = 10;

	UPROPERTY(EditDefaultsOnly, Category = "ProceduralMesh")
	float Offset = 100.0f;

	virtual void BeginPlay() override;

# pragma region Components
protected:

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;

# pragma endregion 

};
