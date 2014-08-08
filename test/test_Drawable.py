import pengine
import time

class TestDrawable(pengine.Drawable):
    def getImage(self):
        if pengine.imageRegistry().contains("test_img") == False:
            pengine.imageRegistry().registerImage("test_img.png", "test_img")
        print "out"
        return pengine.imageRegistry().get("test_img")


pengine.startPengine();
pengine.initScreen(640, 480);
# testD = TestDrawable();
print pengine.imageRegistry().contains("test_img")
print pengine.imageRegistry().registerImage("test_img.png", "test_img")
print pengine.imageRegistry().contains("test_img")
# pengine.registerDrawable(testD);
# pengine.render();

time.sleep(5)
