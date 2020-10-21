#include <linux/init.h>             // Macros used to mark up functions e.g., __init __exit
#include <linux/module.h>           // Core header for loading LKMs into the kernel
#include <linux/sched.h>            // Contains types, macros, functions for the kernel

int simple_init(void){
   printk("Hello for the init function");
   return 0;
}

void simple_exit(void){
   printk("Hello from the exit function");
}
 
/** @brief A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(simple_init);
module_exit(simple_exit);