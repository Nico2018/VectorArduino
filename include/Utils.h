#ifndef UTILS_H
#define UTILS_H
#include <Arduino.h>
#define DBG_IFACE Serial
#define DBG_BAUD 115200

class Utils
{
public:
    static void DBG(String msg)
    {
        static bool dbg_initialized = false;
        if (!dbg_initialized)
        {
            DBG_IFACE.begin(DBG_BAUD);
            dbg_initialized = true;
        }
        DBG_IFACE.println(msg);
    }
    template <typename T>
    static void Swap(T &a, T &b)
    {
        T c = a;
        a = b;
        b = c;
    }
};

#endif //UTILS_H