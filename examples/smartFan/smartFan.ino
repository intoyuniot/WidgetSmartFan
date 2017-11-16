/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 智能风扇：控制风扇开关

 所需器件:
 1.风扇
 2.继电器模块

 接线说明:

 继电器模块                   核心板
 1.DC+：                      +5V
 2.DC-：                      GND
 3.IN：                       D0
 4.NO：                       风扇的正极
 5.COM：                      +5V
 6.NC：                       悬空
 7.触发选择端：选择跳线与high短接, 即高电平触发。
 */


#include <WidgetSmartFan.h>

 #define CONTROL_PIN D0

WidgetSmartFan smartFan = WidgetSmartFan();

void smartFanCb(void)
{
    if(smartFan.getFanSwitch())
    {
        smartFan.control(CONTROL_PIN,1); //打开风扇
    }
    else
    {
        smartFan.control(CONTROL_PIN,0);//关闭风扇
    }
}

void setup()
{
    //初始化
    smartFan.begin(smartFanCb);
}

void loop()
{
}
