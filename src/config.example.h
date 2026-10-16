#pragma once

// ---- Edit these before flashing ----

#define WIFI_SSID     "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// URL of the raw 1-bit bitmap your backend serves.
// Must be exactly WIDTH * HEIGHT / 8 bytes, MSB-first, 1 = white / 0 = black
// (GxEPD2's expected packed format).
#define IMAGE_URL "http://192.168.1.50:5000/calendar.bin"

// How often to check for a new image, in minutes.
#define REFRESH_INTERVAL_MINUTES 20
