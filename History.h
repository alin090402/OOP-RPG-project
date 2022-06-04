//
// Created by ALIN on 02.06.2022.
//

#ifndef RPG_HISTORY_H
#define RPG_HISTORY_H

#include <ostream>
#include <deque>

///As putea sa fac clasa template sa accepte doar alte clase care mostenesc Record
template<typename T> class History;

template<typename T>
class History {
public:
    History() = default;
    History& operator += (const T& record){
        records.push_back(record);
        while((int)records.size() > maximRecords)
            records.pop_front();
        return *this;
    }

    std::vector<T> GetLast(int n){
        if(n >(int) records.size())
            n = (int)records.size();
        return std::vector<T>(records.end() - n, records.end());
    }
    [[maybe_unused]]void setMaximRecords(int maximRecords_){
        maximRecords = maximRecords_;
    }
    ///returneaza ultimele n inregistrari
private:
    int maximRecords = 1000;
    std::deque<T> records;
};




#endif //RPG_HISTORY_H
