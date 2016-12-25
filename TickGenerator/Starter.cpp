// TickGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TickGenerator.h"
#include <iostream>

class TestListener : public TickListener {

    virtual void on_tick() {
        std::cout << "listener tick called" << std::endl;
    }

};


int main()
{
    TestListener test;

    TickGenerator::add_listener(&test);
    TickGenerator::start();
    
    while (true) {}

    return 0;
}

