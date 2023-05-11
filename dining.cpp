#include <iostream>
#include <unistd.h>
#include "philosopher.h"

philosopher::philosopher(int id) : _id(id), eaten(0) { }

void philosopher::set_chopstick(chopstick *first) {
    this->first = first;
}

int philosopher::pick_first() {
    cout << "Philosopher " << _id << " wants to pick up " << first->get_id() << endl;
    int result = first->pick_up();
    cout << "Philosopher " << _id << " picked up " << first->get_id() << endl;

    return result;
}

int philosopher::try_pick_second(chopstick* second) {
    cout << "Philosopher " << _id << " tries to pick up " << second->get_id() << endl;

    int result = second->try_to_pick();

    if(result == 0) {
        this->second = second;
        cout << "Philosopher " << _id << " picked up " << second->get_id() << endl;
    } else {
        cout << "Philosopher " << _id << " could not pick up " << second->get_id() << "! It was already picked up!" << endl;
    }

    return result;
}

int put(int id, chopstick* chop) {
    int result = chop->put_down();

    cout << "Philosopher " << id << " put down " << chop->get_id() << "\n" << endl;

    return result;
}

int philosopher::put_first() {
    return put(_id, first);
}

int philosopher::put_second() {
    return put(_id, second);
}

int philosopher::get_id() {
    return _id;
}

void philosopher::eat() {
    cout << "\nPhilosopher " << _id << " is eating for " << ++eaten << " time!\n" << endl;
    usleep(10000);
}
