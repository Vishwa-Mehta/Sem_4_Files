// WAP a C program to simulate paging
//
// take input:
// size of physical memory
// size of logical memory
// partition size
// logical address
// base address
// calc physical address: phy addr = base addr + (frame number * frame size) + offset
#include <stdio.h>
int main() {
	int phy_size;
	int log_size;
	int partition_size;
	int log_addr;
	int base_addr;
	int phy_addr;
	printf("enter the size of physical memory, size of logical memory, partition size, logical address, base address: \n");
	scanf("%d %d %d %d %d", &phy_size, &log_size, &partition_size, &log_addr, &base_addr);
	int total_frames = phy_size/partition_size;
	int frame_size = partition_size;
	int frame_no = log_addr;
	int offset = 5;
	phy_addr = base_addr + (frame_no * frame_size) + offset;
	printf("Physical address = %d\n", phy_addr);
	return 0;
}
