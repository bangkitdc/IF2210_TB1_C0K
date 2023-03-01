#include "inventoryHolder.hpp"

InventoryHolder::InventoryHolder() : InventoryHolder("-") { }

InventoryHolder::InventoryHolder(string type) {
    this->type = type;
}

InventoryHolder::~InventoryHolder() { }

