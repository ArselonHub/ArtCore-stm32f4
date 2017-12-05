/*
 * FilteredEdgeDetector.h
 *
 *  Created on: Dec 17, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_LEVELDETECTOR_H_
#define SOURCE_ART_LEVELDETECTOR_H_

#include <Art/Device.h>
#include <Art/Thread.h>
#include <Art/CoreTimer.h>
#include <Art/CoreEdgeDetector.h>

namespace Art
{

	class LevelDetector : public Device
	{
	public:
		LevelDetector();

		Signal<void*> onEvent() SIGNAL;

		Word period();
		void setPeriod(Word value);
		Bool level() const;
		Pin* pin();
		Word setPin(Pin* value);

		Edge edge() const;
		void setEdge(Edge edge);

		Thread* thread() const;
		void setThread(Thread* thread);

	private:
		class EdgeDetector : public CoreEdgeDetector
		{
			virtual void doEventSvc();
		};

		class EventTask : public Task
		{
			virtual void execute();
		};

		class LevelTimer : public CoreTimer
		{
	        virtual void doTimeoutSvc();
		};

		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		Byte			m_level;
		Edge			m_edge;
		Word			m_period;
		Thread*			m_thread;
		EdgeDetector	m_edgeDetector;
		EventTask		m_eventTask;
		LevelTimer		m_levelTimer;
	};

	inline Word LevelDetector::period()
	{
		return m_period;
	}

	inline void LevelDetector::setPeriod(Word value)
	{
		m_period = value;
	}

	inline Bool LevelDetector::level() const
	{
		return m_level;
	}

	inline Pin* LevelDetector::pin()
	{
		return m_edgeDetector.pin();
	}

	inline Word LevelDetector::setPin(Pin* value)
	{
		return m_edgeDetector.setPin(value);
	}

	inline Art::Edge LevelDetector::edge() const
	{
		return m_edge;
	}

	inline void LevelDetector::setEdge(Edge edge)
	{
		m_edge = edge;
	}

	inline Thread* LevelDetector::thread() const
	{
		return m_thread;
	}

	inline void LevelDetector::setThread(Thread* thread)
	{
		m_thread = thread;
	}

}

#endif
