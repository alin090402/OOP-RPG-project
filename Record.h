//
// Created by ALIN on 02.06.2022.
//

#ifndef RPG_RECORD_H
#define RPG_RECORD_H

#include <ostream>

/// Record Interface
class Record {
public:
    bool operator<(const Record &rhs) const;

    Record();
        friend std::ostream &operator<<(std::ostream &os, const Record &record);

private:
    const long long timestamp;
    virtual void Afisare(std::ostream &ostream) const = 0;
};


#endif //RPG_RECORD_H
