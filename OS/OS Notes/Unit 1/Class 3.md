### Caching:
- performed at many levels (hardware, OS, software)
- info copied from slower to faster storage temporarily
- faster storage is checked first : if it's there in cache then info is directly taken

### I/O Structure:
- general purpose comp systems use bus
	- Bus is a collection of wires which enable to communicate with other devices
		- these can be twisted pair, coaxial cable or optical fibre
		- types : SYSTEM BUS :-
			- data
			- address
			- control
- each device controller handles a specific device
- **Small Computer-Systems Interface** (SCSI) controller enables to connect more devices. (other types CAN, I2C)
- device controller has a local buffer and set of special regs.
- responsible for moving data b/w peripheral devices
- After I/O starts control will return to the user only after completion of I/O task
- During this time CPU is idle until next interrupt using the wait instruction
- No simultaneous I/O processes
- I/O starts -> control returns to user program -> I/O completes meanwhile
	- **System call** : request to OS to tell user to wait for I/O to finish
	- **Device-status table** : has I/O device entries (type, address, state)
- OS indexes into table -> check status -> modify table entry (includes interrupt)

### Direct Device Access Structure:
~~DEVICE -> CPU -> MEMORY~~
DEVICE -> MEMORY :))
- access memory w/o intervention of CPU
- fasterrrrr
- for high-speed I/O devices
- transmission is close to memory speeds
- light weighted process (LWP), saves address space and resources while other threads can go on with other processes
