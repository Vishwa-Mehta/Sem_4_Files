Program that runs all the time is called "KERNEL". Everything else is either a System Program or an Application Program.

### Device driver:
- In charge of a particular device
	- has a local buffer
	- has registers for action to take place
	- I/O : device -> local buffer
	- CPU : memory <-> local buffer
	- informs CPU that it's done with the task using an **interrupt**

### Booting:
-> Cold booting : initial boot
-> Warm booting : restart
	- on boot the first program that runs is called *Bootstrap* has size 8KB.
	- stored in ROM or EEPROM
	- Bootstrap is AKA **firmware**
	- Initialises all the aspects of the system
	- must know how to load the OS and start excecuting the system.
	- locates and loads the KERNEL.
	- first program created is *init* after OS is booted and waits for an event to occur

### Interrupt:
- transfers control to interrupt service through **interrupt vector** that contains addr of all service-routines
	- saves address of interrupted instruction
	- trap/exception : software generated interrupt caused by error or user request
	- OS is intrrupt driven
	- OS saves the state of CPU using registers and program counters
	- Types:
		- Polling
		- vectored interrupt signal
	- Action to be taken for each interrupt determined by code segment

### Storage Structure:
1. Main memory:
	- large storage media
	- RAM : volatile
3. ROM, EEPROM
	- mobiles have EEPROM
	- Instruction Execution:
		- fetch -> decode -> execute -> store : **VON NEUMANN ARCHITECTURE**
		- Fetch : RAM
		- Decode : Control Unit
		- Execute : ALU
		- Store : RAM
