#ifndef ART_ABSTRACTTIMER_H
#define ART_ABSTRACTTIMER_H

#include <Art/BasicList.h>
#include <Art/BasicQueue.h>
#include <Art/Sit.h>
#include <Art/Task.h>
#include <Art/Types.h>

namespace Art
{    

    class CoreTimer
    {
    public:
    	CoreTimer();
		void start(ShortL interval);
		void startSvc(ShortL interval);
		void startWithJiffies(Int value);
		void startWithJiffiesAhead(Int value);
		void startWithJiffiesAheadSwi(Int value);
		
        void startWithMoment(const Moment moment);
        void startWithMomentSwi(const Moment moment);
        void stopSvc();
        Moment moment();
        void setMoment(Moment value);
        void synchronizeMoment();
        void stop();
        Bool isRunning();

    protected:
        virtual void doTimeoutSvc() = 0;

    private:
        static void startWithJiffiesSwiImp(CoreTimer* timer, Int jiffes);
        static void startWithJiffiesAheadSwiImp(CoreTimer* timer, Int jiffies);
        static void startWithMomentSwiImp(CoreTimer* timer, Moment moment);
        static void stopSwiImp(CoreTimer* timer);
        static void processSitTimeoutSvcImp();

		CoreTimer* m_next;
        CoreTimer* m_previous;		
        Moment m_moment;

        class TimerList : public BasicList<CoreTimer>
        {
        public:
        	TimerList();
        };

        static TimerList s_list;
        static volatile Bool s_canSchedule;

        friend class BasicList<CoreTimer>;
        friend class BasicQueue<CoreTimer>;
        friend class Pmcc;
        friend void Sit::processTick();
    };

    inline CoreTimer::CoreTimer()
    {
    	m_next = 0;
    }

	inline void CoreTimer::startWithJiffiesAheadSwi(Int value)
	{
		startWithJiffiesAheadSwiImp(this, value);
	}

	inline void CoreTimer::startWithMomentSwi(const Moment moment)
	{
		startWithMomentSwiImp(this, moment);
	}

	inline void CoreTimer::stopSvc()
	{
		stopSwiImp(this);
	}

	inline void CoreTimer::synchronizeMoment()
	{
		m_moment = Sit::currentMoment();
	}

	inline Bool CoreTimer::isRunning()
	{
		return m_next != 0;
	}

	inline Moment CoreTimer::moment()
	{
		return m_moment;
	}

	inline void CoreTimer::setMoment(Moment value)
	{
		m_moment = value;
	}
}

#endif
