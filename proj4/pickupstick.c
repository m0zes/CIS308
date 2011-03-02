#include "pickupstick.h"

int Add(struct PickupStick *node) {
	struct PickupStick *curr = root;
	int out = 0;
	while (curr != NULL) {
		if (curr->stick == node->stick) {
			break;
		}
		if (curr->next->stick == node->next->stick) {
			node->next = curr->next->next;
			curr->next = node;
			out = 1;
			break;
		}
	}
}
