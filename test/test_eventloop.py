import pengine
import time

pen = pengine.Pengine()
pen.initScreen(640, 480)

start = time.time()

while time.time() - start < 5:
    pen.processEvents();