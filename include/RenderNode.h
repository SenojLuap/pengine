// RenderNode.h by Paul R Jones (paujo) on 8.28.2014

#ifndef PAUJO_RENDERNODE_H
#define PAUJO_RENDERNODE_H

#include <vector>
#include "RenderJob.h"


#ifdef __cplusplus
extern "C" {
#endif

  struct RenderNode {
    int layer;
    std::vector<RenderJob*> *jobs;
    RenderNode *left;
    RenderNode *right;

    RenderNode(int);
    ~RenderNode();
    void addJob(int layer, RenderJob *job);
    void getRenderList(std::vector<RenderJob *> &);
    void clear();
  };

#ifdef __cplusplus
}
#endif

#endif
