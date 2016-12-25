#include "TickGenerator.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono_literals;

std::vector<TickListener*> TickGenerator::m_listeners = std::vector<TickListener*>();
std::thread* TickGenerator::m_runner = nullptr;
bool TickGenerator::run = false;

void TickGenerator::add_listener(TickListener* listener) {
    TickGenerator::m_listeners.emplace_back(listener);
}


void TickGenerator::generate_tick() {
    
    while (run) {
        for (auto it = TickGenerator::m_listeners.begin(); it != TickGenerator::m_listeners.end(); ++it) {
            (*it)->on_tick();
        }

        // sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));

        std::cout << "tick" << std::endl;
    }
}


void TickGenerator::start() {
    
    run = true;
    delete m_runner;
    m_runner = new std::thread(TickGenerator::generate_tick);

}