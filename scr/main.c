#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2

// Tarea 1: Temporizador / Sensor virtual (Prioridad Media)[cite: 3]
void task_sensor(void *pvParameter) {
    int contador = 0;
    while(1) {
        contador++;
        printf("Tarea 1 [Sensor Virtual]: Lectura actual = %d\n", contador);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Se ejecuta cada 1 segundo[cite: 3]
    }
}

// Tarea 2: Control de LED (Prioridad Alta)[cite: 3]
void task_led(void *pvParameter) {
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    int estado = 0;
    while(1) {
        estado = !estado;
        gpio_set_level(LED_PIN, estado);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Parpadea muy rápido, cada 500ms[cite: 3]
    }
}

// Tarea 3: Envío de reporte serial (Prioridad Baja)[cite: 3]
void task_reporte(void *pvParameter) {
    while(1) {
        printf("Tarea 3 [Reporte]: El sistema FreeRTOS funciona correctamente sin bloqueos.\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Se ejecuta cada 2 segundos[cite: 3]
    }
}

void app_main() {
    printf("Iniciando Sistema Multitarea con FreeRTOS...\n");
    
    // Creación de las tareas usando xTaskCreate con diferentes prioridades (3 es la más alta)[cite: 3]
    xTaskCreate(task_led, "Task_LED", 2048, NULL, 3, NULL);
    xTaskCreate(task_sensor, "Task_Sensor", 2048, NULL, 2, NULL);
    xTaskCreate(task_reporte, "Task_Reporte", 2048, NULL, 1, NULL);
}
