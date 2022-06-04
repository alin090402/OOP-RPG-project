//
// Created by ALIN on 02.06.2022.
//

#include <vector>
#include "History.h"


/*template<typename T>
History<T> &operator += (History<T> &history, const T &record)
{
    history.records.push_back(&record);
    while(history.records.size() > history.maximRecords)
        history.records.pop_front();
    return history;
}*/

template<typename T>
void History<T>::Sort() {
    sort(records.begin(), records.end());
}
/*
template<typename T>
std::vector<T> History<T>::GetLast(int n) {
    if(n > records.size())
        n = records.size();
    return std::vector<T>(records.end() - n, records.end());
}*/

template<typename T>
void History<T>::setMaximRecords(int maximRecords_) {
    maximRecords = maximRecords_;
}
