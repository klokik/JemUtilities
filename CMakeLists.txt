cmake_minimum_required (VERSION 2.6)
project (JemUtils)

set (JemUtils_VERSION_MAJOR 1)
set (JemUtils_VERSION_MINOR 0)

option(BACKLIGHT "Build backlight  control binary" ON)
option(BLUETOOTH "Build modified brcm_patchram" OFF)

if (BACKLIGHT)
		add_executable(backlight_set ${PROJECT_SOURCE_DIR}/src/backlight_set.cpp)
endif(BACKLIGHT)

if (BLUETOOTH)
#  find_package(bluez-libs... REQUIRED)
  add_executable(brcm_patchram_plus ${PROJECT_SOURCE_DIR}/src/brcm_patchram_plus.c)
  target_link_libraries(brcm_patchram_plus bluetooth)
endif(BLUETOOTH)
