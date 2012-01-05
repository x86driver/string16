LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    string.cpp \

LOCAL_C_INCLUDES := frameworks/base/include
#LOCAL_C_INCLUDES += /home/shane/source/include/ /home/shane/source/include/freetype2
#LOCAL_C_INCLUDES += external/sdl_ttf
#LOCAL_C_INCLUDES += vendor/garmin/external/ustl
LOCAL_SHARED_LIBRARIES := libutils
#LOCAL_STATIC_LIBRARIES := libSDL libSDL_ttf libfreetype libustl
#LOCAL_SHARED_LIBRARIES := libts
LOCAL_CFLAGS += -Wall

LOCAL_MODULE:= string

include $(BUILD_EXECUTABLE)

