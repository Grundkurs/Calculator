//
// Created by keen on 20/04/2017.
//

#include <iostream>
#include "Compute.hpp"

Compute::Compute()
: mLHS(), mRHS(), mState(State::LHS), mOperator(Type::Plus), mResult(0.f){

}


State Compute::getState() {
    return mState;
}

void Compute::setSign(int sign) {

}

bool Compute::lhsEmpty() const {
    return mLHS.empty();
}

bool Compute::rhsEmpty() const {
    return mRHS.empty();
}


void Compute::setOperator(Type type) {
    mOperator = type;
}

void Compute::compute() {
    if(mLHS.empty() || mRHS.empty()) return;

    float lhs = std::stof(mLHS);
    float rhs = std::stof(mRHS);
    float result;

    char sign;
    switch(mOperator) {
        case (Type::Minus): {
            sign = '-';
            break;
        }
        case (Type::Plus): {
            sign = '+';
            break;
        }
        case (Type::Multiply): {
            sign = '*';
            break;
        }
        case (Type::Divide): {
            sign = '/';
            break;
        }
    }
    std::cout << mLHS << " " << sign << " " << mRHS << " = ";
    switch(mOperator){
        case(Type::Minus):{
            result = lhs - rhs;
            break;
        }
        case(Type::Plus):{
            result = lhs + rhs;
            break;
        }
        case(Type::Multiply):{
            result = lhs * rhs;
            break;
        }
        case(Type::Divide):{
            result = lhs / rhs;
            break;
        }
    }
    mResult = result;
    mLHS = std::to_string(mResult);
    mRHS.clear();

}


float Compute::getResult() const {
    return mResult;
}


void Compute::setState(State state) {
    mState = state;
}


void Compute::reset() {
    mLHS.clear();
    mRHS.clear();
    mState = State::LHS;
    mResult = 0;
}


void Compute::addDigit(int digit) {
    std::string temp = std::to_string(digit);
    if(mState == State::LHS){
        mLHS.append(temp);
    }
    else {
        mRHS.append(temp);

    }
}


