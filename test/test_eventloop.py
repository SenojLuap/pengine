import pengine
import time

class TestListener(pengine.MouseListener) :
    def mouseButtonClicked(self, event):
        print "mouseButtonClicked"
    
    def mouseMoved(self, event) :
        print "mouseMoved"

    def mouseWheelMoved(self, event) :
        print "mouseWheelMoved"

pen = pengine.Pengine()
pen.initScreen(640, 480)

tl = TestListener();
pen.mouse.registerListener(tl);

start = time.time()

while time.time() - start < 15:
    pen.processEvents();
