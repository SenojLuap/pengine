// RenderNode.cpp by Paul R Jones (paujo) on 8.28.2014

#include "RenderNode.h"

// Ctor.
RenderNode::RenderNode(int layer) : layer(layer) {
  jobs = new std::vector<RenderJob*>();
  left = NULL;
  right = NULL;
}

// Add a job to the tree.
void RenderNode::addJob(int layer, RenderJob *job) {
  if (this->layer == layer) {
    jobs->push_back(job);
  } else if (layer < this->layer) {
    if (left == NULL)
      left = new RenderNode(layer);
    left->addJob(layer, job);
  } else {
    if (right == NULL)
      right = new RenderNode(layer);
    right->addJob(layer, job);
  }
}

// Get all the RenderJobs in this node and its children.
void RenderNode::getRenderList(std::vector<RenderJob*> &list) {
  if (left != NULL)
    left->getRenderList(list);
  for (std::vector<RenderJob*>::iterator i = jobs->begin(); i != jobs->end(); ++i)
    list.push_back(*i);
  if (right != NULL)
    right->getRenderList(list);
}
