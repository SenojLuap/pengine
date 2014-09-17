// RenderJob.cpp by Paul R Jones (paujo) on 9.17.2014

#include "RenderJob.h"

// Ctor.
RenderJob::RenderJob(int image, int posX, int posY, double scale, double rotation, int rotationOriginX,
		     int rotationOriginY, bool flipHorizontal, bool flipVertical) : image(image) {
  placement = Placement(posX, posY, scale, rotation, rotationOriginX, rotationOriginY, flipHorizontal, flipVertical);
}

// Ctor.
RenderJob::RenderJob(int image, Placement placement) : image(image), placement(placement) { }
