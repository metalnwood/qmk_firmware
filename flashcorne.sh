sudo time
sleep 5
sudo dfu-programmer atmega32u4 erase --force
sudo dfu-programmer atmega32u4 flash crkbd_rev1_maw.hex
sudo dfu-programmer atmega32u4 reset
