/*
 * Monitor.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_MONITOR_H_
#define SOURCE_ART_PRIVATE_MONITOR_H_

#include <Art/Private/Detector.h>
#include <Art/Task.h>

namespace Art
{
	namespace Private
	{
		class Monitor
		{
		public:
			void processInterrupt(UWord ir);
			void registerDetector(Detector* detector, UWord flag);
			void unregisterDetector(Detector* detector);
			UWord svcMask();
		private:
			class SvcTask : public Task
			{
				virtual void execute();
			};

			BasicList<Detector>	m_irqDetectors;
			BasicList<Detector> m_svcDetectors;

			UWord		m_irqMask;
			UWord		m_svcMask;
			UWord		m_svcFlags;
			SvcTask		m_svcTask;

			friend class Detector;
		};

		inline UWord Monitor::svcMask()
		{
			return m_svcMask;
		}

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_MONITOR_H_ */
