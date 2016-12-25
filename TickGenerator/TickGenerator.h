#pragma once

#include <vector>
#include "TickListener.h"
#include <thread>

class TickGenerator
{
public:
    void static add_listener(TickListener* listener);
    void static generate_tick();
    void static start();
    void static stop();
    void static restart();


private:
    
    TickGenerator();
    ~TickGenerator() {};
    static const unsigned int delay_ms = 1000;

public:

private:
    static std::vector<TickListener*> m_listeners;
    static std::thread* m_runner;
    static bool run;

};

