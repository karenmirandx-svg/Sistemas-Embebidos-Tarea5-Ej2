Tarea 5 - Sistemas Embebidos: Ejercicio 2 (FreeRTOS)

Este repositorio contiene la solución al Ejercicio 2 de la Tarea 5, enfocado en el diseño de un sistema multitarea utilizando el sistema operativo en tiempo real FreeRTOS sobre el framework ESP-IDF en un microcontrolador ESP32.

Descripción del Proyecto
El código demuestra la ejecución concurrente de múltiples tareas con diferentes niveles de prioridad, evitando el bloqueo del sistema (a diferencia de un loop secuencial tradicional) mediante la correcta gestión de temporización.

Tareas Implementadas:
- Task_LED (Prioridad 3 - Alta): Controla el parpadeo de un LED en el GPIO 2 con una frecuencia alta (500ms).
- Task_Sensor (Prioridad 2 - Media): Simula la lectura periódica de un sensor mediante un temporizador, enviando el valor al monitor serial cada 1000ms.
- Task_Reporte (Prioridad 1 - Baja): Envía periódicamente (cada 2000ms) un reporte del estado del sistema por el puerto serial.

Se utiliza la función `vTaskDelay()` en lugar de retardos bloqueantes convencionales para ceder el control del procesador (scheduler) y permitir el paralelismo real de las funciones.

Instrucciones de Compilación y Ejecución
1. Clonar o descargar este repositorio en su máquina local.
2. Abrir la carpeta del proyecto en **Visual Studio Code** con la extensión **PlatformIO** instalada.
3. Hacer clic en el icono de **Build** (✓) en la barra inferior de PlatformIO para compilar el código.
4. Para simular el sistema, asegúrese de tener la extensión de **Wokwi** instalada, abra el archivo `diagram.json`, presione `F1` y seleccione `Wokwi: Start Simulator`.
