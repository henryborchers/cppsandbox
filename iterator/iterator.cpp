//
// Created by henry on 10/27/19.
//
#include <iostream>
using std::cout;
using std::endl;

struct Counter{
public:
    struct CounterIterator{
        int value;
        explicit CounterIterator(int value):value(value){};
        int &operator*(){
            return value;
        }

        bool operator!=(const CounterIterator &other){
            return value != other.value;
        }
        CounterIterator *operator++(){
            this->value++;
            return this;
        }
    };


    explicit Counter(int max): max_value(max){}
    typedef CounterIterator iterator;

    iterator begin(){
        return CounterIterator(0);
    }
    iterator end(){
        return CounterIterator(max_value);
    }
private:
    int max_value;
};


void range_based_example();

void standard_for_loop_example();

int main(int argc, char* argv[]){
    range_based_example();

    standard_for_loop_example();
    return 0;
}

void standard_for_loop_example() {
    Counter counter2(15);
    for(Counter::CounterIterator it=counter2.begin(); it != counter2.end(); ++it){
        cout << "couter is at " << *it << endl;
    }
}

void range_based_example() {
    Counter range(5);
    for(auto const counter: range){
        cout << "couter is at " << counter << endl;
    }
}
