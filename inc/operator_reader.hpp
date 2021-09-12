#ifndef __OPERATOR_READER_HPP__
#define __OPERATOR_READER_HPP__

#include <vector>
#include <utility>
#include <QString>

#include "operator.hpp"

class OperatorReader {
    public:
        std::pair<bool, std::vector<Operator>> requestOperators(QString mcc);
};

#endif /* __OPERATOR_READER_HPP__ */
