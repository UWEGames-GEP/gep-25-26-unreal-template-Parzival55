#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemData.h"
#include "PlayerInventoryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GEP_TEMPLATE_API UPlayerInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    UPlayerInventoryComponent();

protected:

    virtual void BeginPlay() override;

public:

    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction
    ) override;

    UPROPERTY(BlueprintReadOnly)
    TArray<FItemData> Inventory;

    UFUNCTION(BlueprintCallable)
    void AddItem(FItemData NewItem);

    UFUNCTION(BlueprintCallable)
    void RemoveItem(FItemData Item);

    UFUNCTION(BlueprintCallable)
    const TArray<FItemData>& GetInventory() const;
};