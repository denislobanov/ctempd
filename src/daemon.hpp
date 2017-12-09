#if !defined (CTD_DAEMON_H)
#define CTD_DAEMON_H

#include <string>
#include <mutex>

class daemon {
    public:
    daemon();
    void run();
    void kill();

    private:
    bool running;
    std::mutex running_lock;

    int read_temp();
    int calculate_fan_speed(int temp);
    void set_fan_speed(int rpm);
};

#endif
