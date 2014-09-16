from pengine import *
import time

class TestThing() :
    
    def __init__ (self, pen) :
        self.pengine = pen
        self.image_handle = pen.imageRegistry.registerImage("./test_img.png")
        self.speed = 100.0 / 1000.0
        self.pos = 0

    def handleKeyboardKey(self, event) :
        if (event.scanCode == KeyboardScanCode.ESCAPE) :
            exit()
        elif (event.scanCode == KeyboardScanCode.I) :
            print "Image handle:", self.image_handle
#        else :
#            print "scancode", event.scanCode

    def tick(self, delta) :
        if (self.pengine.keyboard.isKeyDown(KeyboardScanCode.RIGHT)) :
            self.pos += self.speed * delta
        elif (self.pengine.keyboard.isKeyDown(KeyboardScanCode.LEFT)) :
            self.pos -= self.speed * delta
        print int(self.pos), self.speed

pen = Pengine()
pen.initScreen(640, 480)

tl = TestThing(pen);
pen.keyboard.registerListener(tl);

start = 0;

while True:
    delta = pen.processEvents();
    tl.tick(delta)
    start += delta
