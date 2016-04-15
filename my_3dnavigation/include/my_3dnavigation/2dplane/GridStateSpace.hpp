#pragma once

#include <2dplane/planestatespace.h>
#include <2dplane/obstaclegrid.h>
#include <Eigen/Dense>


/**
 * @brief A 2d plane with continuous states and discretized obstacles.
 * @details The state space is broken up into a grid with the given discrete height and widths.
 */
class GridStateSpace : public PlaneStateSpace {
public:
    GridStateSpace(float width, float height, int discretizedWidth, int discretizedHeight);

    /**
     * Returns a boolean indicating whether the given point is within bounds and obstacle-free.
     */
    bool stateValid(const Eigen::Vector2f &pt) const;
    bool transitionValid(const Eigen::Vector2f &from, const Eigen::Vector2f &to) const;

    Eigen::Vector2f intermediateState(const Eigen::Vector2f &source, const Eigen::Vector2f &target, float minStepSize, float maxStepSize) const;

    const ObstacleGrid &obstacleGrid() const;
    ObstacleGrid &obstacleGrid();

private:
    ObstacleGrid _obstacleGrid;
};
