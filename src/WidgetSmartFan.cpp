#include "WidgetSmartFan.h"



WidgetSmartFan::WidgetSmartFan(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    sprintf(pCmdSwitchTopic,"channel/smartFan_%d/cmd/switch",_Item);
    sprintf(pDataStatusTopic,"channel/smartFan_%d/data/status",_Item);
}

WidgetSmartFan::~WidgetSmartFan()
{

}

void WidgetSmartFan::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetSmartFan::getFanSwitch(void)
{
    return _switchKey;
}

void WidgetSmartFan::displayFanStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

void WidgetSmartFan::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayFanStatus(ucVal);
}

void WidgetSmartFan::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey=1;
    }
    else
    {
        _switchKey=0;
    }

    _EventCb();
}


