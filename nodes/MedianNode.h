//
// Created by makstar on 06.12.2020.
//

#ifndef FILTERS_MEDIANNODE_H
#define FILTERS_MEDIANNODE_H

#include "ANode.h"
#include "ISubject.h"
#include <cassert>
#include <algorithm>

class MedianNode: public ANode, public ISubject<MedianNode> {
private:
    int N;//N must fall between 1 and 5

    void setMedian(int mdn);
    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
    int getPositionMedian(std::vector<double> vec);
    void process() override;

public:
    friend class SetMedianCommand;

    int getMedian() const;

    NodeType getNodeType() override;
};


#endif //FILTERS_MEDIANNODE_H
