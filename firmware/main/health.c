#include "health.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "health";

static void health_task(void *parameter)
{
    uint32_t uptime = 0;

    while (true)
    {
        ESP_LOGI(TAG,
                 "System operational | uptime=%" PRIu32 " seconds",
                 uptime++);

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void start_health_task(void)
{
    xTaskCreate(
        health_task,
        "health_task",
        4096,
        NULL,
        5,
        NULL);
}