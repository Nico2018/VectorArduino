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
    int arr[5] = {9, 8, 7, 6, 5};
    Vector<int> v, v2(arr, 5);
    Utils::DBG("v size:" + String(v.Size()));
    v.PushBack(2);
    Utils::DBG("v size:" + String(v.Size()));
    v.PushFront(4);
    Utils::DBG("v size:" + String(v.Size()));
    v.PushFront(9);
    v.PushFront(4);

    for (int i = 0; i < v.Size(); i++)
    {
        Utils::DBG("v[" + String(i) + "] = " + String(v[i]));
    }

    for (int i = 0; i < v2.Size(); i++)
    {
        Utils::DBG("v2[" + String(i) + "] = " + String(v2[i]));
    }

    v.Clear();

    Utils::DBG("v size after clear:" + String(v.Size()));

    v.PushBack(6);
    v.PushBack(2);
    v.PushBack(1);
    v.PushBack(0);

    v.Sort([](int &a, int &b) -> bool { return a > b; });

    for (int i = 0; i < v.Size(); i++)
    {
        Utils::DBG("v[" + String(i) + "] = " + String(v[i]));
    }

    int last = *v.PopBack();
    Utils::DBG("Last item of v is equal to = " + String(last));
    int first = *v.PopFront();
    Utils::DBG("First item of v is equal to = " + String(first));

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
