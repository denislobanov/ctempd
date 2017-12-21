#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>

#include "daemon.hpp"

extern "C" {
#include "comm-host.h"
#include "ec_flash.h"
#include "common.h"
#include "ec_commands.h"
}

// main loop, trap sigkil
void daemon::run() {
    using namespace std::chrono_literals;
    using namespace std::this_thread;

    // synchronise kill
    std::scoped_lock{running_lock};
    running = true;
    while(running) {
        int temp = read_temp();

        int speed = calculate_fan_speed(temp);

        set_fan_speed(speed);

        // sleep until next check.
        sleep_for(2s);
    }
}

void daemon::kill() {
    std::cout<<"stopping main thread"<<std::endl;
    running = false;

    // block on run()
    std::scoped_lock{running_lock};
}

int daemon::read_temp() {
    std::cout<<"reading temperature"<<std::endl;

    uint8_t val;
    int rv = ec_readmem(EC_MEMMAP_TEMP_SENSOR, sizeof(val), &val);

    std::cout<<"ret code: "<<rv<<" temp: "<<val<<std::endl;

    return val;
}

int daemon::calculate_fan_speed(int temp) {
    // call into fan profile module to calculate this.
    // for now we just hard code.
    return 15;
}

void daemon::set_fan_speed(int rpm) {
    std::cout<<"setting fan speed to "<<rpm<<std::endl;
}

