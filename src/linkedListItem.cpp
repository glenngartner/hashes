//
// Created by glenn on 9/20/2017.
//

#include "linkedListItem.h"

linkedListItem::linkedListItem(std::string *key, std::string *value) {
    this->key = *key;
    this->value = *value;
    this->next = nullptr;
}
