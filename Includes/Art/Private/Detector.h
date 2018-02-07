/*
 * Detector.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_DETECTOR_H_
#define ART_PRIVATE_DETECTOR_H_

#include <Art/Device.h>
#include <Art/BasicList.h>

namespace Art
{
	enum ExecutionLevel
	{
		ExecutionLevelIrq,
		ExecutionLevelSvc,
		ExecutionLevelThread
	};

	namespace Private
	{
		class Monitor;

		class Detector : public Device
		{
		public:
			virtual ~Detector();

		protected:
			UWord flag() const;
			virtual ExecutionLevel executionLevel() const;

		private:
			virtual void doEventIrq();
			virtual void doEventSvc();

			Detector*		m_next;
			Detector*		m_previous;
			UWord			m_flag;

			friend class Monitor;
			friend class BasicList<Detector>;
		};

		inline UWord Detector::flag() const
		{
			return m_flag;
		}
} /* namespace Private */
} /* namespace Art */

#endif
