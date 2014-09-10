import pengine
import time

class TestListener(pengine.MouseListener) :
    def handleMouseButton(self, event):
        print "mouseButtonClicked", event.toString()
    
    def handleMouseMotion(self, event) :
        print "mouseMoved", event.toString()

    def handleMouseWheel(self, event) :
        print "mouseWheelMoved", event.toString()

pen = pengine.Pengine()
pen.initScreen(640, 480)

tl = TestListener();
pen.mouse.registerListener(tl);

start = time.time()

while time.time() - start < 10:
    pen.processEvents();
