from pengine import *
import time

class TestThing() :
    
    def __init__ (self, pen) :
        self.pengine = pen
        self.image_handle = pen.imageRegistry.registerImage("./test_img.png")
        self.speed = 100.0 / 1000.0
        self.placement = Placement()
        self.x = 0.0;
        self.y = 0.0;

    def handleKeyboardKey(self, event) :
        if (event.scanCode == KeyboardScanCode.ESCAPE) :
            exit()
        elif (event.scanCode == KeyboardScanCode.I) :
            print "Image handle:", self.image_handle
#        else :
#            print "scancode", event.scanCode

    def tick(self, delta) :
        if (self.pengine.keyboard.isKeyDown(KeyboardScanCode.RIGHT)) :
            self.x += self.speed * delta
        elif (self.pengine.keyboard.isKeyDown(KeyboardScanCode.LEFT)) :
            self.x -= self.speed * delta
        if (self.pengine.keyboard.isKeyDown(KeyboardScanCode.DOWN)) :
            self.y += self.speed * delta
        elif (self.pengine.keyboard.isKeyDown(KeyboardScanCode.UP)) :
            self.y -= self.speed * delta
        print self.x, self.y

pen = Pengine()
pen.initScreen(640, 480)

tl = TestThing(pen);
pen.keyboard.registerListener(tl);

start = 0;

framerate = 1.0 / 60.0
start = time.time()

while True:
    delta = pen.processEvents();
    tl.tick(delta)
    delta = float(delta) / 1000
    time.sleep(abs(framerate - delta))
    
