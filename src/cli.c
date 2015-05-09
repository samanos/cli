#include <stdio.h>

#include "protocol.h"
#include "usb_interface.h"

int main() {
  usb_device_id device_id = {
    .vendor_id = VENDOR_ID,
    .vendor_name = VENDOR_NAME,
    .product_id = PRODUCT_ID,
    .product_name = PRODUCT_NAME
  };

  uint8_t reply[32];
  int8_t length = transfer_data2(&device_id, REQUEST_BRIDGE_STATUS, 0, reply, sizeof(reply));
  if (length >= 0) {
    printf("Reply has size: %02X\n", length);
    printf("First reply bytes: %02X %02X %02X %02X\n", reply[0], reply[1], reply[2], reply[3]);
  }
  else {
    printf("No reply. Length %02X\n", length);
  }

  return 0;
}
