//
// Created by ALIN on 02.06.2022.
//

#include "Record.h"

std::ostream &operator<<(std::ostream &os, const Record &record) {
    record.Afisare(os);
    return os;
}

Record::Record() : timestamp(time(nullptr)) {}

bool Record::operator<(const Record &rhs) const {
    return timestamp < rhs.timestamp;
}

