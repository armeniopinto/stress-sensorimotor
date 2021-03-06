/*
 * @file Motion.h
 * @brief The library that deals with the robot's movement.
 * @author Arménio Pinto
 *
 * Copyright (C) 2015, 2016 by Arménio Pinto.
 * Please read the file LICENSE for the license details.
 */

#ifndef MOTION_H_
#define MOTION_H_

#include "Runtime.h"
#include "OrientationPerception.h"

class Motion {
public:
	/** @brief The possible motion speeds. */
	enum Speed {
		SLOW, NORMAL, FAST
	};

	Motion(Runtime& runtime, OrientationPerception& orientation);

	void init();

	/** @brief Sets the left servo duty cycle. */
	void setLeft(int duty);

	/** @brief Sets the right servo duty cycle. */
	void setRight(int duty);

	/** @brief Immediately (abruptly) stops the robot's movement. */
	void freeze();

	/** @brief Gracefully stops the robot's movement. */
	void stop();

	/** @brief Moves the robot forward at the fastest speed. */
	void go();

	/** @brief Moves the robot forward at a specific speed. */
	void go(Speed speed);

	/** @brief Moves the robot backwards at the fastest speed. */
	void reverse();

	/** @brief Moves the robot backwards at a specific speed. */
	void reverse(Speed speed);

	/** @brief Rotates the robot to the left indefinitely. */
	void turnLeft(Speed speed);

	/** @brief Rotates the robot to the left at an angle. */
	void turnLeft(int angle);

	/** @brief Rotates the robot to the right indefinitely. */
	void turnRight(Speed speed);

	/** @brief Turns Rotate robot to the right at an angle. */
	void turnRight(int angle);

private:
	Runtime& _runtime;
	OrientationPerception& _orientation;
};

#endif
