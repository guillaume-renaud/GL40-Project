#ifndef OBSERVER
#define OBSERVER

#include <string>
#include <set>
#include <iostream>
using namespace std;

class IObserver
{
public:
    virtual void update() = 0;
};

class Observable
{
private:
    set<IObserver*> list_observers;

public:
    void notify() const
    {
        // Notifier tous les observers
                for (set<IObserver*>::const_iterator it = list_observers.begin();
                          it != list_observers.end(); ++it)
            (*it)->update();
    }

    void addObserver(IObserver* observer)
    {
        // Ajouter un observer a la liste
        list_observers.insert(observer);
    }

    void removeObserver(IObserver* observer)
    {
        // Enlever un observer a la liste
        list_observers.erase(observer);
    }
};

#endif // OBSERVER

