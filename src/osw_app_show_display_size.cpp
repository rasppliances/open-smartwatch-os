
#include "osw_app_show_display_size.h"

#include <gfx_util.h>
#include <osw_app.h>
#include <osw_hal.h>

// OswAppHelloWorld::OswAppHelloWorld(void) : OswApp() {}

void OswAppShowDisplaySize::loop(OswHal* hal) {
  static uint8_t chunkHeight = 2;

  static long loopCount = 0;
  loopCount++;
  Graphics2D* gfx = hal->getCanvas()->getGraphics2D();
  gfx->fill(rgb565(255, 0, 0));

  // gfx->drawCircle(119, 119, 119, rgb565(255, 255, 255));
  // gfx->drawCircle(119, 120, 119, rgb565(255, 255, 255));
  // gfx->drawCircle(120, 119, 119, rgb565(255, 255, 255));
  // gfx->drawCircle(120, 120, 119, rgb565(255, 255, 255));

  uint16_t height = gfx->getHeight();

  for (uint16_t y = 0; y < height; y += chunkHeight) {
    float y1 = (y + (y < height / 2 ? chunkHeight : 0)) - height / 2.0;
    float d = sqrt(120 * 120 - y1 * y1);
    uint16_t xOffset = 120 - d;
    uint16_t chunkWidth = ceil(d * 2);
    gfx->fillFrame(xOffset, y, chunkWidth, chunkHeight, rgb565(0, 0, 0));
  }

  if (loopCount % 30 == 0) {
    chunkHeight = chunkHeight * 2;
    if (chunkHeight >= 32) {
      chunkHeight = 1;
    }
  }

  // gfx->drawHLine(0, 119, 240, rgb565(255, 255, 255));
  // gfx->drawVLine(119, 0, 240, rgb565(255, 255, 255));

  hal->getCanvas()->setTextColor(rgb565(255, 255, 255));
  hal->getCanvas()->setCursor(24, 119);
  hal->getCanvas()->print("Chunk Height: ");
  hal->getCanvas()->print(chunkHeight);
}
