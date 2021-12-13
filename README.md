#AmbiRoom

SUMMARY

The python code takes pixel data of the screen and calculates the average color.
To make the code run fast yet accurate, it measures the GCD of the screen size amount of pixels, for FHD this corresponds to GCD(1080, 1920) = 144 pixels
NodeMCU creates a local web server
Python code sends data (average RGB of the pixels) over TCP
NodeMCU reads incoming data and drives the LEDs

IMPORTANT
- Change the dimensions in the screen.py file to fit your monitor if necessary, default is 1080x1920 pixels (FHD)
- Find the IP addresses of your NodeMCU board (local IP, gateway IP, subnet mask, DNS)
- Change the IP addresses in the .ino file with them
