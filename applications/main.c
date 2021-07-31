/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 * 2019-1-10      e31207077    add stm32f767-st-nucleo bsp
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define THREAD_STACK_SIZE   1024
#define THREAD_PRIORITY     20
#define THREAD_TIMESLICE    10

#define SENSOR_SOIL_MOISTURE_PIN  GET_PIN(C, 0)

struct rt_thread thread;
static char thread_stack[THREAD_STACK_SIZE];

static void thread_entry(void* parameter)
{
    rt_pin_mode(SENSOR_SOIL_MOISTURE_PIN, PIN_MODE_INPUT);
    while (1)
    {
        uint8_t humi = rt_pin_read(SENSOR_SOIL_MOISTURE_PIN);
        rt_kprintf("Soil moisture:%d\n" ,humi);
        rt_thread_delay(1000);
    }

}

int main(void)
{
    rt_thread_init(&thread,"SensorSoilMoisture",thread_entry, RT_NULL,&thread_stack[0], sizeof(thread_stack),THREAD_PRIORITY + 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread);

    return RT_EOK;		
}
