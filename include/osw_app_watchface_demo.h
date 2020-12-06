#ifndef OSW_APP_WATCH_FACE_DEMO_H
#define OSW_APP_WATCH_FACE_DEMO_H

#include <osw_hal.h>

#include "osw_app.h"

class OswAppWatchFaceDemo : public OswApp {
 public:
  OswAppWatchFaceDemo(){};
  void setup(OswHal* hal);
  void loop(OswHal* hal);
  ~OswAppWatchFaceDemo(){};

 private:
};

#endif