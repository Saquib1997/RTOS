---
# RTOS Assignment
---
---
### Question 1:
---
* For the Free RTOS priority mechanism is Higher the Number Higher the priority
* asd
---
---
### Question 2:
---
* In case of Free RTOS we use API vTaskDelay(x/portTICK_PERIOD_MS) to make the task periodic with 'x' second
---
---
### Question 3:
---

---
---
### Question 4 & 5:
---
* Conclusion from this activity is that higher priority task will run first in RTOS i.e. RTOS has Priority based Preemptive Scheduling 
---
---
### Question 6:
---
* 
---
---
### Question 7:
---
* Free RTOS uses scheduling algorithm of "Fixed Priority Pre-emptive Scheduling with Time Slicing"
---
---
### Question 8:
---
* The Customization options in Free RTOS for creating a task are:
    1. 

---
---
### Question 9:
---
* The TCB stores the address of the stack start address in pxStack and the current top of stack in pxTopOfStack. It also stores a pointer to the end of the stack in pxEndOfStack to check for stack overflow if the stack grows "up" to higher addresses. If the stack grows "down" to lower addresses then stack overflow is checked by comparing the current top of stack against the start of stack memory in pxStack.
* The TCB stores the initial priority of the task in uxPriority and uxBasePriority. A task is given a priority when it is created, and a task's priority can be changed. If FreeRTOS implements priority inheritance then it uses uxBasePriority to remember the original priority while the task is temporarily elevated to the "inherited" priority.
* Each task has two list items for use in FreeRTOS's various scheduling lists. When a task is inserted into a list FreeRTOS doesn't insert a pointer directly to the TCB. Instead, it inserts a pointer to either the TCB's xGenericListItem or xEventListItem. These xListItem variables let the FreeRTOS lists be smarter than if they merely held a pointer to the TCB.
* A task can be in one of four states: running, ready to run, suspended, or blocked. You might expect each task to have a variable that tells FreeRTOS what state it's in, but it doesn't. Instead, FreeRTOS tracks task state implicitly by putting tasks in the appropriate list: ready list, suspended list, etc. The presence of a task in a particular list indicates the task's state. As a task changes from one state to another, FreeRTOS simply moves it from one list to another.
---
---
### Question 10:
---
* Task States in case of Free RTOS after creation of tasks are:
    * Ready
    * Running
    * Blocked
    * Suspended
    * Deleted
---
---
### Question 11:
---
* API for deleting a Task is: vTaskDelete(TaskHandle_t Handle).
---
---
### Question 12:
---
* 
