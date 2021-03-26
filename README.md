# Vector

Minimal vector implementation for embeded systems like arduino without STL

## Usage

```cpp
#include <Arduino.h>
#include <Utils.h>
#include <Vector.h>

void setup()
{
    // put your setup code here, to run once:
    Vector<int> v;
    Utils::DBG("v size:" + String(v.Size()));
    v.Push(2);
    Utils::DBG("v size:" + String(v.Size()));
    v.Push(4);
    Utils::DBG("v size:" + String(v.Size()));

    for (int i = 0; i < v.Size(); i++)
    {
        Utils::DBG("v[" + String(i) + "] = " + String(v[i]));
    }

    v.Clear();

    Utils::DBG("v size after clear:" + String(v.Size()));

    v.Push(6);
    v.Push(2);
    v.Push(1);
    v.Push(0);

    v.Sort([](int &a, int &b) -> bool { return a > b; });

    for (int i = 0; i < v.Size(); i++)
    {
        Utils::DBG("v[" + String(i) + "] = " + String(v[i]));
    }
}

void loop()
{
    // put your main code here, to run repeatedly:
}
```
