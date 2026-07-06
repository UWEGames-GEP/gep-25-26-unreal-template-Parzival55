#include "PlayerInventoryComponent.h"

UPlayerInventoryComponent::UPlayerInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UPlayerInventoryComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(
        DeltaTime,
        TickType,
        ThisTickFunction);
}

void UPlayerInventoryComponent::AddItem(FItemData NewItem)
{
    Inventory.Add(NewItem);

    UE_LOG(LogTemp, Warning, TEXT("Added %s"),
        *NewItem.DisplayName);
}

void UPlayerInventoryComponent::RemoveItem(FItemData Item)
{
    Inventory.Remove(Item);

    UE_LOG(LogTemp, Warning, TEXT("Removed %s"),
        *Item.DisplayName);
}

const TArray<FItemData>& UPlayerInventoryComponent::GetInventory() const
{
    return Inventory;
}