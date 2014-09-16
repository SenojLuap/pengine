import pengine
import time

class TestListener(pengine.MouseListener) :
    def handleMouseButton(self, event):
        print "mouseButtonClicked", event.toString()
    
    def handleMouseMotion(self, event) :
        print "mouseMoved", event.toString()

    def handleMouseWheel(self, event) :
        print "mouseWheelMoved", event.toString()
        
    def handleKeyboardKey(self, event) :
        print "keyboardKey", event.toString(), " ", event.scanCode
        if (event.scanCode == pengine.KeyboardScanCode.ESCAPE) :
            exit()
    

pen = pengine.Pengine()
pen.initScreen(640, 480)

tl = TestListener();
pen.mouse.registerListener(tl);
pen.keyboard.registerListener(tl);

start = time.time()

while True:
    pen.processEvents();
