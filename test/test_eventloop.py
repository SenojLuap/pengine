import pengine
import time

pen = pengine.Pengine()
pen.initScreen(640, 480)

start = time.time()

while time.time() - start < 15:
    pen.processEvents();
    if pen.mouse.leftButtonState() == pengine.SwitchState.pressed:
        print "You pressed the left mouse button!"
