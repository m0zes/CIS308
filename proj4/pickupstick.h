#ifndef PICKUPSTICK_H
#define PICKUPSTICK_H

struct PickupStick {
	int stick;
	struct PickupStick *next;
};

struct PickupStick *root;

int Add(struct PickupStick *node);

int Check();

#endif
