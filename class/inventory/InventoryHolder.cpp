#include "InventoryHolder.hpp"

InventoryHolder::InventoryHolder(string type): type(type) {
}

void InventoryHolder::setType(string type){
    this->type = type;
}

string InventoryHolder::getType()
{
    return this->type;
}
