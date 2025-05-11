#pragma once
#include "List.h"
#include "Event.h"

class Dialog : public List {
protected:
    int EndState;
public:
    Dialog(void);
    ~Dialog(void);
    void GetEvent(TEvent& event);
    int Execute();
    void HandleEvent(TEvent& event);
    void ClearEvent(TEvent& event);
    int Valid();
    void EndExec();
};