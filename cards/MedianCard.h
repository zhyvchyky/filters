//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_MEDIANCARD_H
#define FILTERS_MEDIANCARD_H

#include "nodes/MedianNode.h"
#include "IObserver.h"

class MedianCard: public IObserver<MedianNode> {
private:
    int median;
public:
    int getMedian();
    void notify(std::shared_ptr<MedianNode>) override;
};


#endif //FILTERS_MEDIANCARD_H
