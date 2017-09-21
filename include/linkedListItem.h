//
// Created by glenn on 9/20/2017.
//

#include <string>

#ifndef HASHES_LINKEDLISTITEM_H
#define HASHES_LINKEDLISTITEM_H


class linkedListItem {

public:
    linkedListItem(std::string *key, std::string *value);
    std::string key;
    std::string value;
    linkedListItem *next;


};


#endif //HASHES_LINKEDLISTITEM_H
