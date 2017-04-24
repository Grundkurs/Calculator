//
// Created by keen on 20/04/2017.
//

#ifndef CALCULATOR_COMPUTE_HPP
#define CALCULATOR_COMPUTE_HPP
#include "Button.hpp"
#include <vector>
enum class State{LHS, RHS};
class Compute {
public:
    Compute();

    State getState();

    void addDigit(int digit);
    bool lhsEmpty() const;
    bool rhsEmpty() const;
    void setOperator(Type type);
    void compute();
    void setState(State state);
    float getResult() const;
    void reset();
    bool isCommaSet() const;
    void setComma();
private:
    std::string mLHS;
    std::string mRHS;
    bool mComma;
    State mState;
    Type mOperator;
    float mResult;
};


#endif //CALCULATOR_COMPUTE_HPP
