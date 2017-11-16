#ifndef WIDGET_SMART_FAN_H_
#define WIDGET_SMART_FAN_H_

#include "application.h"

class WidgetSmartFan: public WidgetBaseClass
{
    public:
        WidgetSmartFan(uint8_t ucItem = 0);
        ~WidgetSmartFan();
        void begin(void (*UserCallBack)(void) = NULL);
        char getFanSwitch(void);
        void displayFanStatus(uint8_t ucVal);
        void control(uint8_t ucPin, uint8_t ucVal);

    private:
        char pCmdSwitchTopic[64];
        char pDataStatusTopic[64];
        char _switchKey = 0;
        uint8_t _Item = 0;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif

