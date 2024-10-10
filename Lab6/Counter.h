#pragma once
class Counter
{
	private:
		int count;
		int IncStep;
	public:
		Counter();
		Counter(int val);
		void setIncrementStep(int val);
		int getCount() const;
		void increment();
		void resetCount(int step = 1);

		Counter operator +(Counter& c) const;
		bool operator >(Counter& c) const;
		bool operator <(Counter& c) const;
		bool operator >=(Counter& c) const;
		bool operator <=(Counter& c) const;
		bool operator ==(Counter& c) const;
		bool operator !=(Counter& c) const;
		void operator +=(Counter& c);
		Counter operator++();
		Counter operator++(int);
};

