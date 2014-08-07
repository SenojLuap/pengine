import pengine
import time

class TestDrawable(pengine.Drawable):
    def getImage():
        if pengine.imageRegistry.contains("test_img") == False:
            pengine.imageRegistry.registerImage("test_img.png", "test_img")
        return pengine.imageRegistry.get("test_img")


pengine.startPengine();
pengine.initScreen(640, 480);
testD = TestDrawable();
pengine.registerDrawable(testD);

time.sleep(5)
